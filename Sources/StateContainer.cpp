#include "StateContainer.hpp"

#include <string>

void StateContainer::add(State const& i_state)
{
	if (!m_states.insert(i_state).second)
		throw std::logic_error("Trying to insert an existing node");
}

void StateContainer::remove(State const& i_state)
{
	if (m_states.find(i_state) == m_states.end())
		throw std::logic_error("Trying to delete a non-existing node");
	m_states.erase(i_state);
}

bool StateContainer::empty() const
{
	return m_states.empty();
}

bool StateContainer::contains(State const& i_rhs) const
{
	return m_states.find(i_rhs) != m_states.end();
}

void StateContainer::clear()
{
	m_states.clear();
}

State const& StateContainer::getBestState() const
{
	if (empty())
		throw std::logic_error("No best state in an empty container");
	return *m_states.cbegin();
}
