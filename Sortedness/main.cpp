#include "Parser.hpp"
#include "State.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char const** argv)
{
	for (auto i = 1; i < argc; ++i)
	{
		const auto file_name = std::string(argv[i]);
		std::ifstream f(file_name);
		std::string query((std::istreambuf_iterator<char>(f)),
		                 std::istreambuf_iterator<char>());
		const auto m = Parser::parse(query);
		const auto s = State(m);
		std::cout << StateUtils::sortedness(s) << std::endl;
	}
}
