#include "catch.hpp"

#include "Parser.hpp"
#include "ResultChecker.hpp"
#include "Solver.hpp"

TEST_CASE("Solver")
{
	SECTION("Already solved")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 8 0
		)";
		const auto opt_solution = Solver::solve(str);
		REQUIRE(opt_solution);
		REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
	}
	SECTION("Nearly solved")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 0 8
		)";
		const auto opt_solution = Solver::solve(str);
		REQUIRE(opt_solution);
		REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
	}
	SECTION("Solvable")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			2 8 3
			6 0 1
			5 7 4
		)";
		const auto opt_solution = Solver::solve(str);
		REQUIRE(opt_solution);
		REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
	}
	SECTION("Unsolvable")
	{
		const auto str =
		R"(
			# This puzzle is unsolvable
			3
			6 2 4
			8 1 5
			7 3 0
		)";
		const auto opt_solution = Solver::solve(str);
		REQUIRE(!opt_solution);
	}
}
