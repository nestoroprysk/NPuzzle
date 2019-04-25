#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include <vector>
#include <optional>
#include <list>

class State
{
public:
	State(SquareMatrix const& i_matrix);
	State(SquareMatrix&& i_matrix);
	auto getAllNeighbours() const -> std::vector<State>;
	State getNeighbour(Move const& i_move) const;
	auto collectMoves() const -> std::list<Move>;
	bool isSolution() const;
	using PredecessorRef = std::reference_wrapper<State const>;
	using MaybePredecessor = std::optional<PredecessorRef>;
	void setPredecessor(State const& i_parent) const;
	MaybePredecessor const& getPredecessor() const;
	SquareMatrix const& getMatrix() const;
	std::size_t& cost() const;
	bool operator<(State const& i_rhs) const;
private:
	SquareMatrix m_matrix;
	mutable MaybePredecessor m_opt_predecessor;
	mutable std::size_t m_path_cost = 0;
};
