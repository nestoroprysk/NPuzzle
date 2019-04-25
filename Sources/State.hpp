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
	State(State const& i_other);
	auto getAllNeighbours() const -> std::vector<State>;
	State getNeighbour(Move const& i_move) const;
	auto collectMoves() const -> std::list<Move>;
	bool isSolution() const;
	// TODO: optimize so as not to store a copy
	using MaybePredecessor = std::shared_ptr<State>;
	void setPredecessor(State const& i_parent) const;
	MaybePredecessor const& getPredecessor() const;
	SquareMatrix const& getMatrix() const;
	std::size_t& cost() const;
	bool operator==(State const& i_rhs) const;
private:
	SquareMatrix m_matrix;
	mutable MaybePredecessor m_opt_predecessor;
	mutable std::size_t m_path_cost = 0;
};
