#pragma once

#include <algorithm>

struct Point
{
	std::size_t i = 0;
	std::size_t j = 0;
};

namespace PointUtils {

namespace Detail {

inline std::size_t diff(std::size_t i_a, std::size_t i_b)
{
    return std::min(i_a - i_b, i_b - i_a);
}

} // namespace Detail

inline std::size_t distance(Point const& i_from, Point const& i_to)
{
    return Detail::diff(i_from.i, i_to.i) + Detail::diff(i_from.j, i_to.j);
}

} // namespace PointUtils
