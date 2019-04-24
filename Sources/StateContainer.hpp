#pragma once

#include <set>

struct State;

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
