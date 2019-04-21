#include "State.hpp"
#include "Parser.hpp"

State::State(std::string const& i_init_state)
{
	m_array = Parser::parse(i_init_state);
	m_moving_point = getPointEmpty();
}

State::State(Matrix const& m_array, Move i_move)
{

}

auto State::getAllNeighbours() -> std::vector<State>
{
	std::vector<State> neighbours;

	neighbours.push_back(State(m_array, Left))
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


void State::setMovingPoint()
{
	auto n = m_array.m_data.size();

	for(auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j++)
			if (m_array.m_data[i][j] == 0)
			{
				m_array.m_data[i][j] = n;
				m_moving_point = {i , j};
			}
	throw std::logic_error("Empty point not found");
}
