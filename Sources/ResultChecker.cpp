#include "ResultChecker.hpp"
#include "State.hpp"

namespace {

using It = std::list<Move>::const_iterator;

auto checkResultImpl(State const& i_state, It const& i_it, It const& i_end) -> ResultChecker::Result
{
    if (i_it == i_end)
        return {i_state.isSolution()};
    return checkResultImpl(i_state.getNeighbour(*i_it), std::next(i_it), i_end);
}

} // namespace anonymous

auto ResultChecker::checkResult(State const& i_state, std::list<Move> const& i_moves) -> Result
{
    return checkResultImpl(i_state, i_moves.cbegin(), i_moves.cend());
}
