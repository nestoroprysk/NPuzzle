#include "Matrix.hpp"
#include <string>
#include <sstream>

std::string Matrix::toString() const
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

bool Matrix::operator==(Matrix const& i_rhs) const
{
	const auto height = m_data.size();
	if (height == 0)
		throw std::logic_error("Invalid empty matrix");
	const auto width = m_data[0].size();
	for (auto const& row : m_data)
		if (row.size() != width)
			throw std::logic_error("Invalid matrix with wariable row size");
	if (i_rhs.m_data.size() != height)
		return false;
	if (i_rhs.m_data[0].size() != width)
		return false;
	for (auto const& row : i_rhs.m_data)
		if (row.size() != width)
			throw std::logic_error("Invalid matrix with wariable row size");
	for (auto i = 0; i < m_data.size(); ++i)
		for (auto j = 0; j < m_data[0].size(); ++j)
			if (i_rhs.m_data[i][j] != m_data[i][j])
				return false;
	return true;
}
