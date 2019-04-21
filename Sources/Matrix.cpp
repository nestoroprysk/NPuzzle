#include "Matrix.hpp"
#include <string>
#include <sstream>
#include <iostream>

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