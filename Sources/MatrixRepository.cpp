#include "MatrixRepository.hpp"

namespace {

Point expectedPosition(std::size_t const i_n, std::size_t const i_nbDimensions)
{
    return {i_n / i_nbDimensions, i_n % i_nbDimensions};
}

MatrixRepository::Sortedness sortedness(State::Id const i_id)
{
    MatrixRepository::Sortedness result = 0;
    const auto& matrix = MatrixRepository::getMatrix(i_id).m_data;
    for (std::size_t i = 0; i < matrix.size(); ++i)
        for (std::size_t j = 0; j < matrix.size(); ++j)
            result += PointUtils::distance({i, j}, expectedPosition(matrix[i][j], matrix.size()));
    return result;
}

} // namespace anonymous

void MatrixRepository::add(State::Id const i_id, SquareMatrix const& i_matrix)
{
    getMatrixRepository().emplace(i_id, i_matrix);
    getSortednessRepository().emplace(i_id, sortedness(i_id));
}

SquareMatrix& MatrixRepository::getMatrix(State::Id const i_id)
{
    return getMatrixRepository().at(i_id);
}

MatrixRepository::Sortedness MatrixRepository::getSortedness(State::Id const i_id)
{
    return getSortednessRepository().at(i_id);
}

std::map<State::Id, SquareMatrix>& MatrixRepository::getMatrixRepository()
{
    static std::map<State::Id, SquareMatrix> g_state_id_to_matrix;
    return g_state_id_to_matrix;
}

std::map<State::Id, MatrixRepository::Sortedness>& MatrixRepository::getSortednessRepository()
{
    static std::map<State::Id, Sortedness> g_state_id_to_sortedness;
    return g_state_id_to_sortedness;
}

void MatrixRepository::flush()
{
    getMatrixRepository().clear();
    getSortednessRepository().clear();
}
