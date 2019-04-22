#include "Solver.hpp"
#include "State.hpp"
#include "StateContainer.hpp"
#include "ResultChecker.hpp"

auto Solver::solve(std::string const& i_file_content) -> Result
{
	const auto content = State(i_file_content);
	StateContainer opened_states;
	opened_states.add(content);
	StateContainer closed_states;
	bool success = false;
	while (!opened_states.empty() && !success){
		const auto& e = opened_states.getBestState();
		if (ResultChecker::sorted(e.m_matrix))
			success = true;
		closed_states.add(e);
		opened_states.remove(e);
		for (auto const& n : e.getAllNeighbours()){
			if (!opened_states.contains(n) && !closed_states.contains(n))
				opened_states.add(n);
			// TODO: implement else
		}
	}
	Result result;
	return result;
}
