#include "StateContainer.hpp"

#include "State.hpp"
#include <string>

void StateContainer::add(State i_state)
{
	if (contains(i_state))
		throw std::logic_error("Trying to insert an existing node");
	m_states.push_back(std::move(i_state));
}

void StateContainer::remove(State const& i_state)
{
	if (!contains(i_state))
		throw std::logic_error("Trying to delete a non-existing node");
    for (auto i = 0; i < m_states.size(); ++i)
    {
        if (m_states[i] == i_state)
        {
            m_states.erase(m_states.begin() + i);
            break;
        }
    }
}

bool StateContainer::empty() const
{
	return m_states.empty();
}

bool StateContainer::contains(State const& i_rhs) const
{
    return find(i_rhs) != std::nullopt;
}

auto StateContainer::find(State const& i_rhs) const -> MaybeState
{
    for (auto const& state : m_states)
        if (state == i_rhs)
            return state;
    return {};
}

void StateContainer::clear()
{
	m_states.clear();
}

State StateContainer::getBestState() const
{
	if (empty())
		throw std::logic_error("No best state in an empty container");
	return *m_states.cbegin();
}

std::size_t StateContainer::size() const
{
    return m_states.size();
}
