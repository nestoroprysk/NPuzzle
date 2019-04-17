#include "gtest/gtest.h"

#include "Dijkstra.hpp"

TEST(basicTests, True)
{
	EXPECT_EQ(Dijkstra::magic(), 42);
}
