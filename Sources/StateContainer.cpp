#include "StateContainer.hpp"

#include "State.hpp"
#include <string>

// TODO: optimize so as to add not a copy
void StateContainer::add(State const& i_state)
{
	if (contains(i_state))
		throw std::logic_error("Trying to insert an existing node");
	m_states.push_back(i_state);
}

void StateContainer::remove(State const& i_state)
{
	if (!contains(i_state))
		throw std::logic_error("Trying to delete a non-existing node");
	m_states.remove(i_state);
}

bool StateContainer::empty() const
{
	return m_states.empty();
}

bool StateContainer::contains(State const& i_rhs) const
{
	return std::any_of(m_states.cbegin(), m_states.cend(),
			[&](auto const& i_state){ return i_state == i_rhs; });
}

void StateContainer::clear()
{
	m_states.clear();
}

// TODO: optimize so as to return not a copy
State StateContainer::getBestState() const
{
	if (empty())
		throw std::logic_error("No best state in an empty container");
	return *m_states.cbegin();
}
