#include "catch.hpp"

#include "Dijkstra.hpp"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Dijkstra::magic() == 42 );
    REQUIRE( Dijkstra::magic() == 0 );
}
