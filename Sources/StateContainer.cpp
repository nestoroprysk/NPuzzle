#include "StateContainer.hpp"

#include "State.hpp"
#include "Utils.hpp"
#include <string>

void StateContainer::push(State i_state)
{
    m_states.insert(std::move(i_state));
}

void StateContainer::pop()
{
    if (m_states.empty())
        throw std::logic_error("Trying to delete a non-existing node");
    m_states.erase(m_states.begin());
}

bool StateContainer::empty() const
{
    return m_states.empty();
}

bool StateContainer::contains(State const& i_rhs) const
{
    const auto matrix = [](auto const i_id) -> SquareMatrix const&{
        return Utils::getMatrixRepository().at(i_id);
    };
    const auto& rhs_matrix = matrix(i_rhs.getId());
    const auto range = m_states.equal_range(i_rhs);
    return std::any_of(range.first, range.second,
        [&matrix, &rhs_matrix](auto const& i_e){
            return matrix(i_e.getId()) == rhs_matrix;
    });
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

std::set<State::Id> StateContainer::getIds() const
{
    std::set<State::Id> result;
    for (auto const& s : m_states)
        result.insert(s.getId());
    return result;
}
