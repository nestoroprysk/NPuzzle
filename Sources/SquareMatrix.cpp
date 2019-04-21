#include "SquareMatrix.hpp"
#include <string>
#include <sstream>

std::string SquareMatrix::toString() const
{
	std::stringstream ss;

	ss << m_data.size() << '\n';

	for (auto const& m_row : m_data)
	{
		for (auto const& a : m_row)
			ss << a << ' ';
		ss << '\n';
	}

	return ss.str();
}

bool SquareMatrix::operator==(SquareMatrix const& i_rhs) const
{
	const auto height = m_data.size();
	if (height == 0)
		throw std::logic_error("Invalid empty SquareMatrix");
	const auto width = m_data[0].size();
	if (height != width)
		throw std::logic_error("Square matrix expected");
	for (auto const& row : m_data)
		if (row.size() != width)
			throw std::logic_error("Invalid SquareMatrix with wariable row size");
	if (i_rhs.m_data.size() != height)
		return false;
	if (i_rhs.m_data[0].size() != width)
		return false;
	for (auto const& row : i_rhs.m_data)
		if (row.size() != width)
			throw std::logic_error("Invalid SquareMatrix with wariable row size");
	for (auto i = 0; i < height; ++i)
		for (auto j = 0; j < width; ++j)
			if (i_rhs.m_data[i][j] != m_data[i][j])
				return false;
	return true;
}
