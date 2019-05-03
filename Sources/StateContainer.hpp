#pragma once

#include "State.hpp"

#include <optional>
#include <queue>
#include <set>

class StateContainer
{
public:
    using MaybeState = std::optional<State>;
	void push(State);
	void pop();
	bool empty() const;
	bool contains(State const&) const;
	State getBestState() const;
	std::size_t size() const;
    std::set<State::Id> const& getIds() const;
private:
	std::priority_queue<State> m_states;
	std::set<State::Id> m_ids;
};
