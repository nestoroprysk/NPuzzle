#pragma once

#include "StateContainer.hpp"
#include <string>
#include <optional>
#include <list>

enum class Move;
class State;

class Solver
{
public:
	Solver() = delete;
	using MaybeResult = std::optional<std::list<Move>>;
	static MaybeResult solve(State const& i_state);
private:
	static void visit(State const& i_state, State const& i_parent);
	static void clear();
private:
	static StateContainer m_opened_states;
	static StateContainer m_closed_states;
};
