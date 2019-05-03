#include "State.hpp"
#include "Utils.hpp"

namespace {

    std::size_t sortedness(State const& i_state)
    {
        std::size_t result = 0;
        std::size_t c = 1;
        const auto& matrix = Utils::getMatrixRepository().at(i_state.getId());
        for (auto const& row : matrix.m_data)
        {
            for (auto n : row)
            {
                const auto diff = n - c;
                result += (diff < 0 ? -diff : diff);
                ++c;
            }
        }
        return result;
    }

} // namespace anonymous

State::State(SquareMatrix const& i_matrix)
    : m_id(Utils::getIdCounter()++)
{
    Utils::getMatrixRepository().emplace(m_id, i_matrix);
}

State::State(State const& i_other)
	: m_opt_predecessor(i_other.m_opt_predecessor)
	, m_id(i_other.m_id)
{
}

auto State::getAllNeighbours() const -> std::vector<State>
{
	std::vector<State> result;
	auto const ms = MoveUtils::possibleMoves(Utils::getMatrixRepository().at(m_id));
	for (auto const m : ms)
		result.push_back(getNeighbour(m));
	return result;
}

State State::getNeighbour(Move i_move) const
{
	return MoveUtils::move(Utils::getMatrixRepository().at(m_id), i_move);
}

bool State::isSolution() const
{
	return SquareMatrixUtils::sorted(Utils::getMatrixRepository().at(m_id));
}

void State::setPredecessor(State const& i_parent) const
{
    m_opt_predecessor = std::make_shared<State>(i_parent);
}

auto State::getPredecessor() const -> MaybePredecessor
{
	return m_opt_predecessor;
}

SquareMatrix const& State::getMatrix() const
{
	return Utils::getMatrixRepository().at(m_id);
}

State::Id State::getId() const
{
    return m_id;
}

bool State::operator==(State const& i_rhs) const
{
	return Utils::getMatrixRepository().at(m_id) ==
	    Utils::getMatrixRepository().at(i_rhs.m_id);
}

bool State::operator<(State const& i_rhs) const
{
    return sortedness(Utils::getMatrixRepository().at(m_id)) <
            sortedness(Utils::getMatrixRepository().at(i_rhs.m_id));
}
