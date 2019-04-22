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
	// TODO: implement
	return {};
}

bool State::operator<(State const& i_rhs) const
{
	// TODO: implement
	return false;
}

bool State::operator==(State const& i_rhs) const
{
	return m_matrix == i_rhs.m_matrix;
}
