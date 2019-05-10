#include "SquareMatrix.hpp"
#include "Utils.hpp"
#include <string>

SquareMatrix::SquareMatrix(SquareArray&& i_array)
    : m_data(std::move(i_array))
    , m_n(m_data.size())
{
}

bool SquareMatrix::operator==(SquareMatrix const& i_rhs) const
{
    if (m_n != i_rhs.m_n)
        return false;
    for (auto i = 0; i < m_n; ++i)
        for (auto j = 0; j < m_n; ++j)
            if (i_rhs.m_data[i][j] != m_data[i][j])
                return false;
    return true;
}

Point SquareMatrixUtils::movingPointCoordinates(SquareMatrix const& i_matrix)
{
    for (std::size_t i = 0; i < i_matrix.m_n; ++i)
        for (std::size_t j = 0; j < i_matrix.m_n; ++j)
            if (i_matrix.m_data[i][j] == Utils::g_moving_point)
                return {i, j};
    throw std::logic_error("No moving point found");
}

bool SquareMatrixUtils::sorted(SquareMatrix const& i_matrix)
{
    auto c = Utils::g_moving_point;
    for (auto const& row : i_matrix.m_data)
        for (auto n : row)
            if (n != c++)
                return false;
    return true;
}

std::string SquareMatrixUtils::toString(SquareMatrix const& i_matrix)
{
    std::string result;
    for (auto const& row : i_matrix.m_data)
    {
        for (auto const& n : row)
            result += std::to_string(n) + ' ';
        result += '\n';
    }
    return result;
}
