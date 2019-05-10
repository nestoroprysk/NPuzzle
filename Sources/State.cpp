#include "State.hpp"
#include "Utils.hpp"

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

namespace {

    Point expectedPosition(std::size_t const i_n, std::size_t const i_nbDimensions)
    {
        if (i_n == 0)
            throw std::logic_error("0 not expected");
        const auto adjusted_n = i_n - 1;
        return {adjusted_n / i_nbDimensions, adjusted_n % i_nbDimensions};
    }

}

std::size_t StateUtils::sortedness(State const& i_state)
{
    std::size_t result = 0;
    const auto& matrix = Utils::getMatrixRepository().at(i_state.getId()).m_data;
    for (std::size_t i = 0; i < matrix.size(); ++i)
        for (std::size_t j = 0; j < matrix.size(); ++j)
            result += PointUtils::distance({i, j}, expectedPosition(matrix[i][j], matrix.size()));
    return result;
}
