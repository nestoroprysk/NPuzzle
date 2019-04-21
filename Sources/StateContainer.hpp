#pragma once

#include "State.hpp"
#include <vector>

class StateContainer
{
public:
	void add();
	void remove();
	bool empty() const;
	bool contains() const;
	State const& getBestState() const;
private:
	std::vector<State> m_states;
};
