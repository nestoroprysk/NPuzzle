#include "catch.hpp"

#include "State.hpp"
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
		const auto opt_solution = Solver::solve(Parser::parse(str));
		REQUIRE(opt_solution);
		REQUIRE(opt_solution->empty());
		REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
	}
	SECTION("Nearly solved 2")
	{
		const auto str =
		R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			7 0 8
		)";
		Solver::MaybeResult opt_solution;
		REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(opt_solution->size() == 1);
		REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
	}
    SECTION("Nearly solved 3")
    {
        const auto str =
                R"(
			# This puzzle is solvable
			3
			1 2 3
			4 5 6
			0 7 8
		)";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(opt_solution->size() == 2);
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
    SECTION("Nearly solved 4")
    {
        const auto str =
                R"(
					# This puzzle is solvable
					3
					1 2 3
					4 0 6
					7 8 5
		)";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(!opt_solution->empty());
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
}
