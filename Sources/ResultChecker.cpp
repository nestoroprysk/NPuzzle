#include "ResultChecker.hpp"

auto ResultChecker::checkResult(SquareMatrix const& i_init_state, std::vector<Move> const& i_moves) -> Result
{
	auto m = i_init_state;
	for (auto const& move : i_moves){
		if (isValid(m, move))
			move(m, move);
		else
			return { false };
	}
	return {};
}
