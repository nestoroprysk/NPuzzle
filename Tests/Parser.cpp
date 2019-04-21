#include "catch.hpp"

#include "Parser.hpp"
#include "TestUtils.hpp"

TEST_CASE("Parser", "[Valid]")
{
	const auto str =
	R"( 3
		1  2 3 
		33 2 5 
		12 3 5 
	)";
	REQUIRE(TestUtils::eq(Parser::parse(str).toString(), str));
}

TEST_CASE("Parser2", "[Valid]")
{
	const auto str =
	R"( 4
		1  2 3 10
		33 2 5 10
		12 3 5 10
		33 2 5 10
	)";
	REQUIRE(TestUtils::eq(Parser::parse(str).toString(), str));
}
