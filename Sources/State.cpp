#include "State.hpp"
#include "Parser.hpp"

State::State(std::string const& i_init_state)
	: m_array(Parser::parse(i_init_state))
{

}

State::State(SquareMatrix const& i_init_state, Move i_move)
{

}

auto State::getAllNeighbours() -> std::vector<State>
{
	return {};
}

bool State::operator<(State const& i_rhs) const
{
	return m_nb_steps_taken < i_rhs.m_nb_steps_taken;
}

bool State::operator==(State const& i_rhs) const
{
	return m_array == i_rhs.m_array &&
		((!mp_prev && !i_rhs.mp_prev) || *mp_prev == *i_rhs.mp_prev) &&
		m_nb_steps_taken == i_rhs.m_nb_steps_taken;
}
