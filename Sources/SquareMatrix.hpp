#pragma once

#include <vector>

struct SquareMatrix
{
	std::vector<std::vector<std::size_t>> m_data;
	std::string toString() const;
	bool operator==(SquareMatrix const& i_rhs) const;
};
