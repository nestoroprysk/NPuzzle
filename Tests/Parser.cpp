#include "catch.hpp"

#include "Parser.hpp"

TEST_CASE("Parser", "[Parser]")
{
	const auto str =
	R"(3
1 2 3 
33 2 5 
12 3 5 
)";
	REQUIRE(Parser::parse(str).toString() == str);
}
