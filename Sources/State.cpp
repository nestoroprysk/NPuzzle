#include "State.hpp"
#include "Utils.hpp"
#include "MatrixRepository.hpp"

State::State(SquareMatrix const& i_matrix)
    : m_id(Utils::getIdCounter()++)
{
    MatrixRepository::add(m_id, i_matrix);
}

State::State(State const& i_other)
    : m_opt_predecessor(i_other.m_opt_predecessor)
    , m_id(i_other.m_id)
{
}

auto State::getAllNeighbours() const -> std::vector<State>
{
    std::vector<State> result;
    auto const ms = MoveUtils::possibleMoves(MatrixRepository::getMatrix(m_id));
    for (auto const m : ms)
        result.push_back(getNeighbour(m));
    return result;
}

State State::getNeighbour(Move i_move) const
{
    return MoveUtils::move(MatrixRepository::getMatrix(m_id), i_move);
}

bool State::isSolution() const
{
    return SquareMatrixUtils::sorted(MatrixRepository::getMatrix(m_id));
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
    return MatrixRepository::getMatrix(m_id);
}

State::Id State::getId() const
{
    return m_id;
}
