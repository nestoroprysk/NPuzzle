#pragma once

#include "Point.hpp"
#include <vector>

struct SquareMatrix
{
    using SquareArray = std::vector<std::vector<std::size_t>>;
    SquareMatrix(SquareArray&& i_array);
    const SquareArray m_data;
    const std::size_t m_n;
    bool operator==(SquareMatrix const& i_rhs) const;
};

namespace SquareMatrixUtils {

Point movingPointCoordinates(SquareMatrix const& i_matrix);
bool sorted(SquareMatrix const& i_matrix);
std::string toString(SquareMatrix const& i_matrix);

} // namespace SquareMatrixUtils
