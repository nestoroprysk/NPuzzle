#include "Move.hpp"

#include "SquareMatrix.hpp"

namespace {

auto swap(SquareMatrix const& i_matrix, Point const a, Point const b) -> SquareMatrix
{
	auto result = i_matrix.m_data;
	std::swap(result[a.i][a.j], result[b.i][b.j]);
	return result;
}

} // namespace anonymous

auto MoveUtils::possibleMoves(SquareMatrix const& i_matrix) -> std::unordered_set<Move>
{
	std::unordered_set<Move> result;
	const auto p = SquareMatrixUtils::biggestCoordinates(i_matrix);
	if (p.i != 0) result.insert(Move::Up);
	if (p.i != i_matrix.m_n - 1) result.insert(Move::Down);
	if (p.j != 0) result.insert(Move::Left);
	if (p.j != i_matrix.m_n - 1) result.insert(Move::Right);
	return result;
}

bool MoveUtils::isValid(SquareMatrix const& i_matrix, Move i_move)
{
	const auto ms = MoveUtils::possibleMoves(i_matrix);
	return ms.find(i_move) != ms.cend();
}

SquareMatrix MoveUtils::move(SquareMatrix const& i_matrix, Move i_move)
{
	if (!MoveUtils::isValid(i_matrix, i_move))
		throw std::logic_error("Invalid move");
	const auto p = SquareMatrixUtils::biggestCoordinates(i_matrix);
	switch (i_move)
	{
		case Move::Left:
			return swap(i_matrix, p, {p.i, p.j - 1});
		case Move::Right:
			return swap(i_matrix, p, {p.i, p.j + 1});
		case Move::Up:
			return swap(i_matrix, p, {p.i - 1, p.j});
		case Move::Down:
			return swap(i_matrix, p, {p.i + 1, p.j});
		default:
			throw std::logic_error("Impossible move");
	}
}
