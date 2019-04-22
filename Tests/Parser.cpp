#include "catch.hpp"

#include "Parser.hpp"
#include "TestUtils.hpp"

TEST_CASE("Parser", "[Valid]")
{
	const auto str =
	R"(
		# This puzzle is solvable
		3
		8 4 6
		2 0 5
		3 7 1
	)";
	REQUIRE(TestUtils::eq(SquareMatrixUtils::toString(Parser::parse(str)), str));
}

TEST_CASE("Parser2", "[Valid]")
{
	const auto str =
	R"(
		# This puzzle is solvable
		4
		10  8 12  5
		 3 14 15  6
		 2  9 11  4
		13  1  0  7
	)";
	REQUIRE(TestUtils::eq(SquareMatrixUtils::toString(Parser::parse(str)), str));
}
