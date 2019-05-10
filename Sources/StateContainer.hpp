#pragma once

#include "State.hpp"

#include <set>
#include <vector>

namespace Detail {

auto const cmp = [](auto const &i_lhs, auto const &i_rhs) {
    return StateUtils::sortedness(i_lhs) < StateUtils::sortedness(i_rhs);
};

}

class StateContainer
{
public:
    using MaybeState = std::shared_ptr<State>;
    void push(State);
    void pop();
    bool empty() const;
    bool contains(State const&) const;
    State getBestState() const;
    std::size_t size() const;
    std::set<State::Id> getIds() const;
private:
    // TODO: research priority queue
    using ContainerType = std::multiset<State, decltype(Detail::cmp)>;
    ContainerType m_states = ContainerType(Detail::cmp);
};
