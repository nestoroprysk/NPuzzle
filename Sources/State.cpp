#include "State.hpp"
#include "Parser.hpp"

State::State(std::string const& i_matrix)
	: m_matrix(Parser::parse(i_matrix))
{
}

State::State(SquareMatrix const& i_matrix, Move i_move)
	: m_matrix(MoveUtils::move(i_matrix, i_move))
{
}

auto State::getAllNeighbours() const -> std::vector<State>
{
	std::vector<State> result;
	auto const ms = MoveUtils::possibleMoves(m_matrix);
	for (auto const m : ms)
		result.emplace_back(m_matrix, m);
	return result;
}

bool State::operator<(State const& i_rhs) const
{
	return m_path_cost < i_rhs.m_path_cost;
}
