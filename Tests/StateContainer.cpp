#include "catch.hpp"

#include "StateContainer.hpp"


TEST_CASE("StateContainer", "[BasicTests]")
{
	State dummy(
		R"(
			# This puzzle is solvable
			3
			8 4 6
			2 0 5
			3 7 1
	)");
	StateContainer sc;
	REQUIRE(sc.empty());
	REQUIRE_THROWS_WITH(sc.remove(dummy), "Trying to delete a non-existing node");
	REQUIRE_NOTHROW(sc.add(dummy));
	REQUIRE_THROWS_WITH(sc.add(dummy), "Trying to insert an existing node");
	REQUIRE(!sc.empty());
	REQUIRE(sc.contains(dummy));
	REQUIRE(sc.getBestState() == dummy);
	REQUIRE_NOTHROW(sc.remove(dummy));
	REQUIRE(!sc.contains(dummy));
}
