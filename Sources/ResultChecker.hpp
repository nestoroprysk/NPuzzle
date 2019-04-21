#pragma once

#include "Move.hpp"
#include "Matrix.hpp"
#include <vector>

namespace ResultChecker {

struct Result
{
	bool m_valid = true;
};

Result checkResult(Matrix const& i_init_state, std::vector<Move> const& i_moves);

} // namespace ResultChecker
