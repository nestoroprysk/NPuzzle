#include "State.hpp"

State::State(SquareMatrix const& i_matrix)
		: m_matrix(i_matrix)
{
}

State::State(SquareMatrix&& i_matrix)
	: m_matrix(std::move(i_matrix))
{
}

auto State::getAllNeighbours() const -> std::vector<State>
{
	std::vector<State> result;
	auto const ms = MoveUtils::possibleMoves(m_matrix);
	for (auto const m : ms)
		result.push_back(getNeighbour(m));
	return result;
}

State State::getNeighbour(Move const& i_move) const
{
	return MoveUtils::move(m_matrix, i_move);
}

auto State::collectMoves() const -> std::list<Move>
{
	std::list<Move> result;
	while (auto opt_c = m_opt_predecessor)
		result.push_front(MoveUtils::inferMove(opt_c->get().m_matrix, m_matrix));
	return result;
}

bool State::isSolution() const
{
	return SquareMatrixUtils::sorted(m_matrix);
}

void State::setPredecessor(State const& i_parent) const
{
	m_opt_predecessor = i_parent;
}

std::size_t& State::cost() const
{
	return m_path_cost;
}

bool State::operator<(State const& i_rhs) const
{
	return m_path_cost < i_rhs.m_path_cost;
}
