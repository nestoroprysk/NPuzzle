#pragma once

#include "Matrix.hpp"
#include "Move.hpp"
#include "Point.hpp"
#include <vector>

class State
{
public:
	State(std::string const& i_init_state);
	State(Matrix const& m_array, Move i_move);
	auto getAllNeighbours() -> std::vector<State>;
	bool operator<(State const& i_rhs) const;
	bool operator==(State const& i_rhs) const;
private:
	Matrix const m_array;
	Point const m_empty_point;
	std::shared_ptr<const State> mp_prev;
	std::size_t m_nb_steps_taken = 0;

	void setEmptyPoint();
};
