#include "Solver.hpp"
#include "State.hpp"
#include "ResultChecker.hpp"
#include "Utils.hpp"
#include "Move.hpp"

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

} // namespace anonymous

auto Solver::solve(State const& i_state) -> MaybeResult
{
    const auto flusher = Utils::ScopedCaller([]{
        Utils::getIdCounter() = 0;
        Utils::getMatrixRepository().clear();
    });

    StateContainer opened_states;
    StateContainer closed_states;

    opened_states.add(i_state);

	while (!opened_states.empty())
    {
		const auto e = opened_states.getBestState();

		if (e.isSolution())
			return {collectMoves(e)};

        opened_states.remove(e);
		closed_states.add(e);

		const auto nnn = e.getMatrix();

		const auto ns = e.getAllNeighbours();
        const auto os = opened_states.size();
        const auto cs = closed_states.size();

		for (auto const& n : ns)
        {
            if (opened_states.contains(n))
                opened_states.remove(n);

		    if (closed_states.contains(n))
                continue;

            if (!opened_states.contains(n))
            {
                n.setPredecessor(e);
                opened_states.add(n);
            }
        }
	}
	return {};
}
