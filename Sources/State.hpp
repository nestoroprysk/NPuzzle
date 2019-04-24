#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include <vector>
#include <optional>
#include <list>

struct State
{
	State(SquareMatrix const& i_matrix);
	State(SquareMatrix&& i_matrix);
	auto getAllNeighbours() const -> std::vector<State>;
	State getNeighbour(Move const& i_move) const;
	auto collectMoves() const -> std::list<Move>;
	bool isSolution() const;
	void setPredecessor(State const& i_parent) const;
	std::size_t& cost() const;
	bool operator<(State const& i_rhs) const;
	using PredecessorRef = std::reference_wrapper<State const>;
	using MaybePredecessor = std::optional<PredecessorRef>;
	SquareMatrix m_matrix;
	mutable MaybePredecessor m_opt_predecessor;
	mutable std::size_t m_path_cost = 0;
};
