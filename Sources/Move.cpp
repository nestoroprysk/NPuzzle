#include "Move.hpp"

#include "SquareMatrix.hpp"

bool MoveUtils::isValid(SquareMatrix const& i_state, Move i_move)
{
	auto mp = i_state.getMovingPoint();
	if (i_move == Move::Left && mp.j == 0)
		return false;
	if (i_move == Move::Right && mp.j == i_state.n - 1)
		return false;
	if (i_move == Move::Up && mp.i == 0)
		return false;
	if (i_move == Move::Down && mp.i == i_state.n - 1)
		return false;
	return true;
}

void MoveUtils::move(SquareMatrix& io_state, Move i_move)
{
	if (!MoveUtils::isValid(io_state, i_move))
		throw std::logic_error("Invalid move");
	auto mp = i_state.getMovingPoint();
	if (i_move == Move::Left){
		std::swap(io_state[mp.i][mp.j], io_state[mp.i][mp.j - 1]);
		return;
	}
	if (i_move == Move::Right){
		std::swap(io_state[mp.i][mp.j], io_state[mp.i][mp.j + 1]);
		return;
	}
	if (i_move == Move::Up){
		std::swap(io_state[mp.i][mp.j], io_state[mp.i - 1][mp.j]);
		return;
	}
	if (i_move == Move::Down){
		std::swap(io_state[mp.i][mp.j], io_state[mp.i + 1][mp.j]);
		return;
	}
}
