#include "SquareMatrix.hpp"
#include <string>
#include <unordered_set>

namespace {

static constexpr auto g_line_break = '\n';
static constexpr auto g_next_elem_delim = ' ';
static constexpr auto g_moving_point = 0;

} // namespace anonymous

SquareMatrix::SquareMatrix(SquareArray&& i_array)
	: m_data(preprocess(validate(std::move(i_array))))
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

auto SquareMatrix::validate(SquareArray&& i_array) -> SquareArray
{
	const auto height = i_array.size();
	if (height == 0)
		throw std::logic_error("Invalid empty SquareMatrix");
	const auto width = i_array[0].size();
	if (height != width)
		throw std::logic_error("Square matrix expected");
	for (auto const& row : i_array)
		if (row.size() != width)
			throw std::logic_error("Invalid SquareMatrix with wariable row size");
	std::unordered_set<std::size_t> s;
	for (auto const& row : i_array)
		for (auto const n : row)
			if (!s.insert(n).second)
				throw std::runtime_error("All the elements in a matrix should be unique");
	for (auto n = 0; n < s.size(); ++n)
		if (s.find(n) == s.end())
			throw std::runtime_error("A range of numbers [0..n*n) is expected");
	return i_array;
}

auto SquareMatrix::preprocess(SquareArray&& i_array) -> SquareArray
{
	for (auto& row : i_array)
	{
		for (auto& n : row)
		{
			if (n == g_moving_point)
			{
				n = i_array.size() * i_array.size();
				return i_array;
			}
		}
	}
	throw std::logic_error("Validation failed");
}

std::string SquareMatrixUtils::toString(SquareMatrix const& i_matrix)
{
	std::string result;
	result += i_matrix.m_n + g_line_break;
	for (auto const& row : i_matrix.m_data)
	{
		for (auto const& a : row)
			result += a + g_next_elem_delim;
		result += g_line_break;
	}
	return result;
}

std::size_t SquareMatrixUtils::biggest(SquareMatrix const& i_matrix)
{
	return i_matrix.m_n * i_matrix.m_n;
}

Point SquareMatrixUtils::biggestCoordinates(SquareMatrix const& i_matrix)
{
	Point result;
	for (std::size_t i = 0; i < i_matrix.m_n; ++i)
		for (std::size_t j = 0; j < i_matrix.m_n; ++j)
			if (i_matrix.m_data[i][j] == SquareMatrixUtils::biggest(i_matrix))
				return {i, j};
	throw std::logic_error("No biggest: validation error");
}
