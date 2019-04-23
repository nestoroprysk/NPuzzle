#pragma once

#include "Move.hpp"
#include "StateContainer.hpp"
#include <string>
#include <optional>
#include <list>

class Solver
{
public:
	Solver() = delete;
	using Result = std::list<Move>;
	using MaybeResult = std::optional<Result>;
	static MaybeResult solve(std::string const& i_file_content);
private:
	static void visit(State const& i_state, State const& i_parent);
	static void clear();
	static auto collect(State const& i_state) -> Result;
private:
	static StateContainer m_opened_states;
	static StateContainer m_closed_states;
};
