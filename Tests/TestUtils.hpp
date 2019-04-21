#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace TestUtils {

inline std::string getTestsDirPath()
{
	return PATH_TO_TESTS_DIR;
}

inline bool eq(std::string const& i_left, std::string const& i_right)
{
	std::stringstream s1(i_left);
	std::stringstream s2(i_right);
	std::vector<std::size_t> left_numbers;
	std::vector<std::size_t> right_numbers;
	for (std::size_t nb; s1 >> nb;)
		left_numbers.push_back(nb);
	for (std::size_t nb; s2 >> nb;)
		right_numbers.push_back(nb);
	if (left_numbers.size() != right_numbers.size())
		return false;
	for (auto i = 0; i < left_numbers.size(); ++i)
		if (left_numbers[i] != right_numbers[i])
			return false;
	return true;
}

} // namespace TestUtils
