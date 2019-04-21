#include "catch.hpp"

#include "StateContainer.hpp"


TEST_CASE("StateContainer", "[BasicTests]")
{
	State dummy(R"( 4
		1  2 3 10
		33 2 5 10
		12 3 5 10
		33 2 5 10
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
