#pragma once

#include "State.hpp"

#include <queue>
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
    std::set<State::Id> const& getIds() const;
private:
    using ContainerType = std::priority_queue<State, std::vector<State>, decltype(Detail::cmp)>;
    ContainerType m_states = ContainerType(Detail::cmp);
	std::set<State::Id> m_ids;
};
