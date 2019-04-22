#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include <vector>

namespace ResultChecker {

bool sorted(SquareMatrix const& i_matrix);

struct Result
{
	bool m_valid = true;
};

Result checkResult(SquareMatrix const& i_matrix, std::vector<Move> const& i_moves, std::size_t i_i = 0);

} // namespace ResultChecker
