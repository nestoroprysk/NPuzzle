#include "catch.hpp"

#include "Parser.hpp"
#include "State.hpp"
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
            0 1 2
            3 4 5
            6 7 8
        )";
        const auto matrix = Parser::parse(str);
        REQUIRE(ResultChecker::checkResult(matrix, {}).m_valid);
    }
    SECTION("Basic valid with single move left")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            1 0 2
            3 4 5
            6 7 8
        )";
        const auto matrix = Parser::parse(str);
        REQUIRE(ResultChecker::checkResult(matrix, {Move::Left}).m_valid);
    }
    SECTION("Basic valid with single move up")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            3 1 2
            0 4 5
            6 7 8
        )";
        const auto matrix = Parser::parse(str);
        REQUIRE(ResultChecker::checkResult(matrix, {Move::Up}).m_valid);
    }
    SECTION("Move down and up identity")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            0 1 2
            3 4 5
            6 7 8
        )";
        const auto matrix = Parser::parse(str);
        REQUIRE(ResultChecker::checkResult(matrix, {Move::Down, Move::Up}).m_valid);
    }
    SECTION("Move right and left identity")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            0 1 2
            3 4 5
            6 7 8
        )";
        const auto matrix = Parser::parse(str);
        REQUIRE(ResultChecker::checkResult(matrix, {Move::Right, Move::Left}).m_valid);
    }
}
