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
	bool operator<(State const& i_rhs) const;
	bool operator==(State const& i_rhs) const;
private:
	Matrix const m_array;
	std::shared_ptr<const State> mp_prev;
	std::size_t m_nb_steps_taken = 0;
};
