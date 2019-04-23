#include "catch.hpp"

#include "Parser.hpp"
#include "TestUtils.hpp"
#include "Move.hpp"

TEST_CASE("Move basics")
{
	const auto s =
	R"(
		# This puzzle is solvable
		3
		8 4 6
		2 0 5
		3 7 1
	)";
	const auto a = Parser::parse(s);
	SECTION("Left")
	{
		const auto s1 =
		R"(
			# This puzzle is solvable
			3
			8 4 6
			0 2 5
			3 7 1
		)";
		const auto e = Parser::parse(s1);
		const auto m = Move::Left;
		REQUIRE(MoveUtils::move(a, m) == e);
		REQUIRE_THROWS_WITH(MoveUtils::move(e, m), "Invalid move");
	}
	SECTION("Right")
	{
		const auto s1 =
		R"(
			# This puzzle is solvable
			3
			8 4 6
			2 5 0
			3 7 1
		)";
		const auto e = Parser::parse(s1);
		const auto m = Move::Right;
		REQUIRE(MoveUtils::move(a, m) == e);
		REQUIRE_THROWS_WITH(MoveUtils::move(e, m), "Invalid move");
	}
	SECTION("Up")
	{
		const auto s1 =
		R"(
			# This puzzle is solvable
			3
			8 0 6
			2 4 5
			3 7 1
		)";
		const auto e = Parser::parse(s1);
		const auto m = Move::Up;
		REQUIRE(MoveUtils::move(a, m) == e);
		REQUIRE_THROWS_WITH(MoveUtils::move(e, m), "Invalid move");
	}
	SECTION("Down")
	{
		const auto s1 =
		R"(
			# This puzzle is solvable
			3
			8 4 6
			2 7 5
			3 0 1
		)";
		const auto e = Parser::parse(s1);
		const auto m = Move::Down;
		REQUIRE(MoveUtils::move(a, m) == e);
		REQUIRE_THROWS_WITH(MoveUtils::move(e, m), "Invalid move");
	}
}

TEST_CASE("Corners")
{
	SECTION("Top-Right")
	{
		const auto s =
		R"(
			# This puzzle is solvable
			3
			8 4 0
			2 7 5
			3 6 1
		)";
		const auto e = Parser::parse(s);
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Up), "Invalid move");
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Right), "Invalid move");
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Down));
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Left));
	}
	SECTION("Top-Left")
	{
		const auto s =
		R"(
			# This puzzle is solvable
			3
			0 4 8
			2 7 5
			3 6 1
		)";
		const auto e = Parser::parse(s);
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Down));
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Right));
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Up), "Invalid move");
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Left), "Invalid move");
	}
	SECTION("Bottom-Right")
	{
		const auto s =
		R"(
			# This puzzle is solvable
			3
			8 4 1
			2 7 5
			3 6 0
		)";
		const auto e = Parser::parse(s);
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Up));
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Right), "Invalid move");
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Down), "Invalid move");
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Left));
	}
	SECTION("Bottom-Left")
	{
		const auto s =
		R"(
			# This puzzle is solvable
			3
			3 4 8
			2 7 5
			0 6 1
		)";
		const auto e = Parser::parse(s);
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Up));
		REQUIRE_NOTHROW(MoveUtils::move(e, Move::Right));
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Down), "Invalid move");
		REQUIRE_THROWS_WITH(MoveUtils::move(e, Move::Left), "Invalid move");
	}
}
