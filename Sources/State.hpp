#pragma once

#include "SquareMatrix.hpp"
#include "Move.hpp"
#include "Point.hpp"
#include <vector>
#include <optional>

struct State
{
	State(std::string const& i_init_state);
	State(SquareMatrix const& i_init_state, Move i_move);
	auto getAllNeighbours() const -> std::vector<State>;
	bool operator<(State const& i_rhs) const;
	using PredecessorRef = std::reference_wrapper<State const>;
	using MaybePredecessor = std::optional<PredecessorRef>;
	SquareMatrix m_matrix;
	mutable MaybePredecessor m_opt_predecessor;
	mutable std::size_t m_path_cost = 0;
};
