#pragma once

#include <list>

struct State;

class StateContainer
{
public:
	void add(State const& i_state);
	void remove(State const&);
	bool empty() const;
	bool contains(State const&) const;
	void clear();
	State getBestState() const;
private:
	std::list<State> m_states;
};
