#include "Solver.hpp"
#include "State.hpp"
#include "ResultChecker.hpp"
#include "Utils.hpp"
#include "Move.hpp"

namespace {

static constexpr auto g_cost = 1;

} // namespace anonymous

StateContainer Solver::m_opened_states;
StateContainer Solver::m_closed_states;

auto Solver::solve(State const& i_state) -> MaybeResult
{
	auto const c = Utils::ScopedCaller(clear);
	m_opened_states.add(i_state);
	while (!m_opened_states.empty())
	{
		const auto& e = m_opened_states.getBestState();
		if (e.isSolution())
			return {e.collectMoves()};
		m_closed_states.add(e);
		const auto ns = e.getAllNeighbours();
		m_opened_states.remove(e);
		std::for_each(ns.cbegin(), ns.cend(),
			[&e](auto const& n){visit(n, e);});
	}
	return {};
}

void Solver::visit(State const& i_state, State const& i_parent)
{
	if (!m_opened_states.contains(i_state) && !m_closed_states.contains(i_state))
	{
		m_opened_states.add(i_state);
		i_state.setPredecessor(i_parent);
	}
	else
	{
		if (i_state.cost() > i_parent.cost() + g_cost)
		{
			i_state.cost() = i_parent.cost() + g_cost;
			i_state.setPredecessor(i_parent);
		}
		if (m_closed_states.contains(i_state))
		{
			m_opened_states.add(i_parent);
			m_closed_states.remove(i_parent);
		}
	}
}

void Solver::clear()
{
	m_opened_states.clear();
	m_closed_states.clear();
}
