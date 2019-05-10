#include "catch.hpp"

#include "Parser.hpp"
#include "TestUtils.hpp"

TEST_CASE("Parser basics")
{
    const auto str =
    R"(
        # This puzzle is solvable
        3
        8 4 6
        2 0 5
        3 7 1
    )";
    const auto e = SquareMatrix(
        {
            {8, 4, 6},
            {2, 0, 5},
            {3, 7, 1}
        }
    );
    REQUIRE(Parser::parse(str) == e);
}

TEST_CASE("Parser basics bigger")
{
    const auto str =
    R"(
        # This puzzle is solvable
        5
        22 20  1  8 14
        24 13 21  4 19
        17  5 16 11  9
        18 12 23  3  7
        10  6  0  2 15
    )";
    const auto e = SquareMatrix(
        {
            {22, 20,  1,  8, 14},
            {24, 13, 21,  4, 19},
            {17,  5, 16, 11,  9},
            {18, 12, 23,  3,  7},
            {10,  6,  0, 2, 15}
        }
    );
    REQUIRE(Parser::parse(str) == e);
}

TEST_CASE("Parser error handling")
{
    SECTION("Non-square")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            8 4
            2 0 5
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "Square matrix expected");
    }
    SECTION("Empty")
    {
        REQUIRE_THROWS_WITH(Parser::parse({}), "Content cannot be empty");
    }
    SECTION("N error")
    {
        const auto str =
        R"(
            31213
            8 4 6
            2 0 5
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "Number indicating the number of should be within the range [3, 64]"
            " (got 31213)");
    }
    SECTION("N and matrix mismatch")
    {
    const auto str =
        R"(
            # This puzzle is solvable
            -1
            8 4 6
            2 0 5
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "Number indicating the number of should be within the range [3, 64]"
            " (got -1)");
    }
    SECTION("Unique numbers")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            8 4 6
            2 6 5
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "All the elements in a matrix should be unique");
    }
    SECTION("Range error")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            3
            8 4 6
            2 9 5
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "A range of numbers [0..n*n) is expected");
    }
    SECTION("Zero")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            5
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "N and parsed matrix side len mismatch: [5,0]");
    }
    SECTION("Too small")
    {
        const auto str =
        R"(
            # This puzzle is solvable
            2
            0 1
            2 3
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "Number indicating the number of should be within the range [3, 64] (got 2)");
    }
    SECTION("Variable len")
    {
    const auto str =
        R"(
            # This puzzle is solvable
            3
            8 4 6
            2 0
            3 7 1
        )";
        REQUIRE_THROWS_WITH(Parser::parse(str), "Invalid SquareMatrix with wariable row size");
    }
}
