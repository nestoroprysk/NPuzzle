#include "catch.hpp"

#include "ResultChecker.hpp"

TEST_CASE("ResultChecker")
{
	SECTION("Basic invalid")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			2 5 4
			7 0 1
			6 8 3
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(!ResultChecker::checkResult(matrix, {}).m_valid);
	}
	SECTION("Basic valid")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 8 0
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(ResultChecker::checkResult(matrix, {}).m_valid);
	}
	SECTION("Basic valid with single move right")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 0 8
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(ResultChecker::checkResult(matrix, {Move::Right}).m_valid);
	}
	SECTION("Basic valid with single move down")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 0
			7 8 6
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(ResultChecker::checkResult(matrix, {Move::Down}).m_valid);
	}
	SECTION("Move up and down identity")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 8 0
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(ResultChecker::checkResult(matrix, {Move::Up, Move::Down}).m_valid);
	}
	SECTION("Move left and right identity")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 8 0
		)";
		const auto matrix = Parser::parse(str);
		REQUIRE(ResultChecker::checkResult(matrix, {Move::Left, Move::Right}).m_valid);
	}
}
