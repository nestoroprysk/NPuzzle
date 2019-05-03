#pragma once

#include "State.hpp"

#include <optional>
#include <vector>

class StateContainer
{
public:
    using MaybeState = std::optional<State>;
	void add(State);
	void remove(State const&);
	bool empty() const;
	bool contains(State const&) const;
	auto find(State const& i_rhs) const -> MaybeState;
	void clear();
	State getBestState() const;
	std::size_t size() const;
private:
	std::vector<State> m_states;
};
