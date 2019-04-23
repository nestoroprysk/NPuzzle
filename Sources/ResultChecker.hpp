#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include "Parser.hpp"
#include <list>

namespace ResultChecker {

bool sorted(SquareMatrix const& i_matrix);

struct Result
{
	bool m_valid = true;
};

Result checkResult(SquareMatrix const& i_matrix, std::list<Move> const& i_moves);

} // namespace ResultChecker
