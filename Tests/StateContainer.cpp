#include "catch.hpp"

#include "State.hpp"
#include "StateContainer.hpp"
#include "Parser.hpp"

TEST_CASE("StateContainer")
{
    State dummy(Parser::parse(
        R"(
            # This puzzle is solvable
            3
            8 4 6
            2 0 5
            3 7 1
    )"));
    StateContainer sc;
    REQUIRE(sc.empty());
    REQUIRE_THROWS_WITH(sc.pop(), "Trying to delete a non-existing node");
    REQUIRE_NOTHROW(sc.push(dummy));
    REQUIRE(!sc.empty());
    REQUIRE(sc.contains(dummy));
    REQUIRE(sc.getBestState().getMatrix() == dummy.getMatrix());
    REQUIRE_NOTHROW(sc.pop());
    REQUIRE(!sc.contains(dummy));
    REQUIRE_NOTHROW(sc.push(dummy));
    REQUIRE(sc.contains(dummy));
}
