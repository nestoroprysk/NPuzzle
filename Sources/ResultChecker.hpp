#pragma once

#include "Move.hpp"
#include <list>

class State;

namespace ResultChecker {

struct Result
{
    bool m_valid = true;
};

Result checkResult(State const& i_state, std::list<Move> const& i_moves);

} // namespace ResultChecker
