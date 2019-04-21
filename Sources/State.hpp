#pragma once

#include "SquareMatrix.hpp"
#include "Move.hpp"
#include "Point.hpp"
#include <vector>

class State
{
public:
	State(std::string const& i_init_state);
	State(SquareMatrix const& i_init_state, Move i_move);
	auto getAllNeighbours() -> std::vector<State>;
	void getMovingPoint();
	bool operator<(State const& i_rhs) const;
	bool operator==(State const& i_rhs) const;
private:
	void setMovingPoint();
	SquareMatrix const m_array;
	Point const m_moving_point;
	std::shared_ptr<const State> mp_prev;
	std::size_t m_nb_steps_taken = 0;
};
