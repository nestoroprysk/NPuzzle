#include "Parser.hpp"
#include <sstream>
#include <iostream>

Matrix Parser::parse(std::string const& i_init_state)
{
	Matrix result;

	std::stringstream ss;
	std::size_t n;
	std::vector<std::vector<std::size_t>> m_data;

	ss << i_init_state;
	ss >> n;

	for (int i = 0; i < n; ++i)
	{
		std::vector<std::size_t> m_row;
		std::size_t a;

		for (int j = 0; j < n; ++j)
		{
			ss >> a;
			m_row.push_back(a);
		}
		m_data.push_back(m_row);
	}

	result.m_data = m_data;

	return result;
}
