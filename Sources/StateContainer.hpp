#pragma once

#include "State.hpp"
#include <set>

class StateContainer
{
public:
	void add(State const&);
	void remove(State const&);
	bool empty() const;
	bool contains(State const&) const;
	State const& getBestState() const;
private:
	std::set<State> m_states;
};
