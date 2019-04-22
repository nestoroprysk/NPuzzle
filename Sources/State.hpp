#pragma once

#include "SquareMatrix.hpp"
#include "Move.hpp"
#include "Point.hpp"
#include <vector>

struct State
{
	State(std::string const& i_init_state);
	State(SquareMatrix const& i_init_state, Move i_move);
	auto getAllNeighbours() const -> std::vector<State>;
	bool operator<(State const& i_rhs) const;
	bool operator==(State const& i_rhs) const;
	SquareMatrix const m_matrix;
};
