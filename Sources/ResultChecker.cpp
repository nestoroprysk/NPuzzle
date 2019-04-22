#include "ResultChecker.hpp"

bool ResultChecker::sorted(SquareMatrix const& i_matrix)
{
	auto c = 0;
	for (auto const& row : i_matrix.m_data)
		for (auto n : row)
			if (n != ++c)
				return false;
	return true;
}

auto ResultChecker::checkResult(SquareMatrix const& i_matrix, std::vector<Move> const& i_moves, std::size_t i_i) -> Result
{
	if (i_i == i_moves.size())
		return {sorted(i_matrix)};
	return ResultChecker::checkResult(MoveUtils::move(i_matrix, i_moves[i_i]), i_moves, i_i + 1);
}
