#pragma once

#include "State.hpp"
#include <set>

class StateContainer
{
public:
	void add(State const& i_state);
	void remove(State const&);
	bool empty() const;
	bool contains(State const&) const;
	void clear();
	State const& getBestState() const;
private:
	std::set<State> m_states;
};
