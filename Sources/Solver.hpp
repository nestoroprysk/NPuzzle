#pragma once

#include "StateContainer.hpp"
#include <string>
#include <list>

enum class Move;
class State;

namespace Solver {

    using MaybeResult = std::shared_ptr<std::list<Move>>;
    MaybeResult solve(State const& i_state);

} // namespace Solver
