#pragma once

#include "Matrix.hpp"
#include "Move.hpp"
#include <vector>

class State
{
public:
	State(std::string const& i_init_state);
	State(Matrix const& i_init_state, Move i_move);
	auto getAllNeighbours() -> std::vector<State>;
private:
	Matrix const m_array;
	std::shared_ptr<const State> m_prev;
};
