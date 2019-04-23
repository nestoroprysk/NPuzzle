#include "ResultChecker.hpp"

namespace {

using It = std::list<Move>::const_iterator;

auto checkResultImpl(SquareMatrix const& i_matrix, It const& i_it, It const& i_end) -> ResultChecker::Result
{
	if (i_it == i_end)
		return {ResultChecker::sorted(i_matrix)};
	return checkResultImpl(MoveUtils::move(i_matrix, *i_it), std::next(i_it), i_end);
}

} // namespace anonymous

bool ResultChecker::sorted(SquareMatrix const& i_matrix)
{
	auto c = 0;
	for (auto const& row : i_matrix.m_data)
		for (auto n : row)
			if (n != ++c)
				return false;
	return true;
}

auto ResultChecker::checkResult(SquareMatrix const& i_matrix, std::list<Move> const& i_moves) -> Result
{
	return checkResultImpl(i_matrix, i_moves.cbegin(), i_moves.cend());
}
