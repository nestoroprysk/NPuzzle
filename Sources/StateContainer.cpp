#include "StateContainer.hpp"

#include "State.hpp"
#include <string>

void StateContainer::push(State i_state)
{
	if (m_ids.find(i_state.getId()) != m_ids.cend())
		throw std::logic_error("Trying to insert an existing node");
	m_ids.insert(i_state.getId());
	m_states.push(std::move(i_state));
}

void StateContainer::pop()
{
	if (m_states.empty())
		throw std::logic_error("Trying to delete a non-existing node");
	m_ids.erase(m_states.top().getId());
    m_states.pop();
}

bool StateContainer::empty() const
{
	return m_states.empty();
}

bool StateContainer::contains(State const& i_rhs) const
{
    return m_ids.find(i_rhs.getId()) != m_ids.cend();
}

State StateContainer::getBestState() const
{
	if (empty())
		throw std::logic_error("No best state in an empty container");
	return m_states.top();
}

std::size_t StateContainer::size() const
{
    return m_states.size();
}

std::set<State::Id> const& StateContainer::getIds() const
{
    return m_ids;
}
