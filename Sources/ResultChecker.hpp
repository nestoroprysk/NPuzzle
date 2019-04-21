#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include <vector>

namespace ResultChecker {

struct Result
{
	bool m_valid = true;
};

Result checkResult(SquareMatrix const& i_init_state, std::vector<Move> const& i_moves);

} // namespace ResultChecker
