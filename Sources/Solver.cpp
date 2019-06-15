#include "Solver.hpp"
#include "State.hpp"
#include "ResultChecker.hpp"
#include "Utils.hpp"
#include "Move.hpp"
#include "MatrixRepository.hpp"

#include <fstream>
#include <iostream>

namespace {

static constexpr auto g_enable_logging_all_states = false;
static constexpr auto g_enable_logging_iteration_time = false;
static constexpr auto g_cout_progress = true;
static constexpr auto g_iteration_limit = 10000;

std::list<Move> collectMovesImpl(State const& i_state,
                                 State::MaybePredecessor const& i_opt_predecessor,
                                 std::list<Move> o_result = std::list<Move>())
{
    if (i_opt_predecessor)
    {
        o_result.push_front(MoveUtils::inferMove(i_opt_predecessor->getMatrix(), i_state.getMatrix()));
        return collectMovesImpl(*i_opt_predecessor, i_opt_predecessor->getPredecessor(), std::move(o_result));
    }
    return o_result;
}

std::list<Move> collectMoves(State const& i_state)
{
    return collectMovesImpl(i_state, i_state.getPredecessor());
}

static std::ofstream g_log("log.txt");

void dump(State const& i_state)
{
    static std::size_t i = 0;
    g_log << ++i << std::endl;
    g_log << SquareMatrixUtils::toString(i_state.getMatrix()) << std::endl;
}

void dump(StateContainer const& i_container)
{
    const auto ids = i_container.getIds();
    if (ids.empty())
        g_log << "Empty" << std::endl << std::endl;
    for (auto id : ids)
        g_log << SquareMatrixUtils::toString(MatrixRepository::getMatrix(id)) << std::endl;
}

void log_initial(State const& i_state)
{
    if (g_enable_logging_all_states)
    {
        g_log << "=== Initial ===" << std::endl;
        dump(i_state);
    }
}

void logProgress(StateContainer const& i_opened_states, StateContainer const& i_closed_states, State const& i_e)
{
    static auto start = std::chrono::steady_clock::now();
    if (g_cout_progress)
    {
        const auto end = std::chrono::steady_clock::now();
        if (g_iteration_limit % 20 == 0)
            std::cout << "Opened [" << i_opened_states.size() << "]        " <<
                         "Closed: [" << i_closed_states.size() << "]       " <<
                         "Sortedness: [" << MatrixRepository::getSortedness(i_e.getId()) << "       ]" <<
                         "Iteration duration: [" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "]" << '\r';
        if (g_enable_logging_iteration_time)
            g_log << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    }

    if (g_enable_logging_all_states)
        {
            g_log << "=New iteration=" << std::endl << std::endl;

            g_log << "Best" << std::endl;
            dump(i_e);

            g_log << "Opened" << std::endl;
            dump(i_opened_states);

            g_log << "Closed" << std::endl;
            dump(i_closed_states);
        }
    start = std::chrono::steady_clock::now();
}

void throwIfIterationLimitExceeded()
{
    static std::size_t iteration_number = 0;
    if (++iteration_number > g_iteration_limit)
    {
        iteration_number = 0;
        throw std::runtime_error("Iteration limit exceeded");
    }
}

} // namespace anonymous

auto Solver::solve(State const& i_state) -> MaybeResult
{
    log_initial(i_state);
    
    const auto flusher = Utils::ScopedCaller([]{
        Utils::getIdCounter() = 0;
        MatrixRepository::flush();
    });

    StateContainer opened_states;
    StateContainer closed_states;

    opened_states.push(i_state);

    while (!opened_states.empty())
    {
        const auto e = opened_states.getBestState();

        logProgress(opened_states, closed_states, e);

        if (e.isSolution())
            return std::make_shared<std::list<Move>>(collectMoves(e));

        opened_states.pop();
        closed_states.push(e);

        const auto ns = e.getAllNeighbours();

        for (auto const& n : ns)
        {
            if (!closed_states.contains(n) && !opened_states.contains(n))
            {
                n.setPredecessor(e);
                opened_states.push(n);
            }
        }

        throwIfIterationLimitExceeded();
    }
    return {};
}
