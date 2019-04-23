#include "Solver.hpp"
#include "State.hpp"
#include "ResultChecker.hpp"
#include "Utils.hpp"

namespace {

static constexpr auto g_cost = 1;

} // namespace anonymous

StateContainer Solver::m_opened_states;
StateContainer Solver::m_closed_states;

auto Solver::solve(std::string const& i_file_content) -> MaybeResult
{
	auto const c = Utils::ScopedCaller(clear);
	auto const content = State(i_file_content);
	m_opened_states.add(content);
	auto i = 0;
	while (!m_opened_states.empty())
	{
		const auto& e = m_opened_states.getBestState();
		if (ResultChecker::sorted(e.m_matrix))
			return {collect(e)};
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
		i_state.m_opt_predecessor = i_parent;
	}
	else
	{
		if (i_state.m_path_cost > i_parent.m_path_cost + g_cost)
		{
			i_state.m_path_cost = i_parent.m_path_cost + g_cost;
			i_state.m_opt_predecessor = i_parent;
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

auto Solver::collect(State const& i_state) -> Result
{
	Result result;
	while (auto opt_c = i_state.m_opt_predecessor)
		result.push_front(MoveUtils::infereMove(opt_c->get().m_matrix, i_state.m_matrix));
	return result;
}
