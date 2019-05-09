#include "Solver.hpp"
#include "State.hpp"
#include "ResultChecker.hpp"
#include "Utils.hpp"
#include "Move.hpp"

#include <fstream>

namespace {

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
        g_log << SquareMatrixUtils::toString(Utils::getMatrixRepository().at(id)) << std::endl;
}

} // namespace anonymous

auto Solver::solve(State const& i_state) -> MaybeResult
{
    g_log << "=== Initial ===" << std::endl;
    dump(i_state);

    const auto flusher = Utils::ScopedCaller([]{
        Utils::getIdCounter() = 0;
        Utils::getMatrixRepository().clear();
    });

    StateContainer opened_states;
    StateContainer closed_states;

    opened_states.push(i_state);

	while (!opened_states.empty())
    {
		const auto e = opened_states.getBestState();

        g_log << "=New iteration=" << std::endl << std::endl;

		g_log << "Best" << std::endl;
        dump(e);

        g_log << "Opened" << std::endl;
        dump(opened_states);

        g_log << "Closed" << std::endl;
        dump(closed_states);

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
	}
	return {};
}
