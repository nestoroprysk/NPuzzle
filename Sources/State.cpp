#include "State.hpp"

namespace {

	std::list<Move> collectMovesImpl(State const& i_state,
			State::MaybePredecessor const& i_predecessor,
			std::list<Move> o_result = std::list<Move>())
	{
		if (const auto& opt_c = i_state.getPredecessor())
		{
			o_result.push_front(MoveUtils::inferMove(opt_c->get().getMatrix(), i_state.getMatrix()));
			return collectMovesImpl(*opt_c, opt_c->get().getPredecessor(), std::move(o_result));
		}
		return o_result;
	}

} // namespace anonymous

State::State(SquareMatrix const& i_matrix)
		: m_matrix(i_matrix)
{
}

State::State(SquareMatrix&& i_matrix)
	: m_matrix(std::move(i_matrix))
{
}

auto State::getAllNeighbours() const -> std::vector<State>
{
	std::vector<State> result;
	auto const ms = MoveUtils::possibleMoves(m_matrix);
	for (auto const m : ms)
		result.push_back(getNeighbour(m));
	return result;
}

State State::getNeighbour(Move const& i_move) const
{
	return MoveUtils::move(m_matrix, i_move);
}

auto State::collectMoves() const -> std::list<Move>
{
	return collectMovesImpl(*this, m_opt_predecessor);
}

bool State::isSolution() const
{
	return SquareMatrixUtils::sorted(m_matrix);
}

void State::setPredecessor(State const& i_parent) const
{
	m_opt_predecessor = i_parent;
}

auto State::getPredecessor() const -> MaybePredecessor const&
{
	return m_opt_predecessor;
}

SquareMatrix const& State::getMatrix() const
{
	return m_matrix;
}

std::size_t& State::cost() const
{
	return m_path_cost;
}

bool State::operator<(State const& i_rhs) const
{
	return m_path_cost + SquareMatrixUtils::sortedness(m_matrix) <
			i_rhs.m_path_cost + SquareMatrixUtils::sortedness(i_rhs.m_matrix);
}
