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
            3
            0 1 2
            3 4 5
            6 7 8
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
            3
            1 0 2
            3 4 5
            6 7 8
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
		            3
		            1 2 0
		            3 4 5
		            6 7 8
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
		            3
		            1 2 5
		            3 0 4
		            6 7 8
        )";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(!opt_solution->empty());
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
    SECTION("Solvable")
    {
        const auto str =
                R"(
                    # This puzzle is solvable
                    3
                    0 2 3
                    1 4 5
                    7 8 6
                    
        )";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(!opt_solution->empty());
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
    SECTION("Solvable 2")
    {
        const auto str =
                R"(
                    # This puzzle is solvable
                    3
                    0 5 2
                    1 8 3
                    4 7 6
        )";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(!opt_solution->empty());
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
        SECTION("Solvable 3")
    {
        const auto str =
                R"(
					# This puzzle is solvable
                        3
                        6 2 5
                        3 7 8
                        4 1 0
        )";
        Solver::MaybeResult opt_solution;
        REQUIRE_NOTHROW(opt_solution = Solver::solve(Parser::parse(str)));
        REQUIRE(opt_solution);
        REQUIRE(!opt_solution->empty());
        REQUIRE(ResultChecker::checkResult(Parser::parse(str), *opt_solution).m_valid);
    }
}
