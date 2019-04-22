#include "Parser.hpp"
#include <sstream>

namespace {

static constexpr auto g_comment = '#';

bool isEmpty(std::string const& i_str)
{
	for (auto ch : i_str)
		if (!std::isspace(ch))
			return false;
	return true;
}

bool isComment(std::string const& i_str)
{
	for (auto ch : i_str)
		if (!std::isspace(ch))
			return ch == g_comment;
	return false;
}

std::size_t getN(std::stringstream& i_ss)
{
	std::size_t result = 0;
	if (std::string s; std::getline(i_ss, s))
		return std::stoi(s);
	throw std::logic_error("N expected");
}

auto split(std::string const& i_str) -> std::vector<std::size_t>
{
	std::stringstream ss(i_str);
	std::size_t n;
	std::vector<std::size_t> result;
	while (ss >> n)
		result.push_back(n);
	return result;
}

void skipComment(std::stringstream& i_ss)
{
	for (std::string s; std::getline(i_ss, s);)
	{
		if (isEmpty(s))
			continue;
		if (!isComment(s))
			throw std::logic_error("Comment expected");
		break;
	}
}

} // namespace anonymous

SquareMatrix Parser::parse(std::string const& i_content)
{
	std::stringstream ss(i_content);

	skipComment(ss);

	auto const n = getN(ss);

	SquareMatrix::SquareArray result;
	
	for (std::string s; std::getline(ss, s);)
		if (!isEmpty(s))
			result.push_back(split(s));

	if (result.size() != n)
		throw std::logic_error(std::string("N and parsed matrix side len mismatch: [") +
			std::to_string(n) + "," + std::to_string(result.size()) + "]\n");

	return result;
}
