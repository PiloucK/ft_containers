#include <vector>
#include <iostream>
#include "myUnitTest.hpp"

// TEST_CASE(Capacity, AccurateReturn, {
// })

TEST_CASE(Vector, Capacity, AccurateReturn, {
	std::vector<int> toto(5, 42);

	EXPECT_EQ(0, 0)
	EXPECT_DIFF(0, 1)
	EXPECT_DIFF(0, 2)
	EXPECT_DIFF(0, 3)
	EXPECT_EQ(toto.size(), 6);
	EXPECT_DIFF(0, 0)
})

TEST_CASE(Vector, Capacity, Bullshit, {
	std::vector<int> toto(5, 42);

	EXPECT_EQ(0, 0)
	EXPECT_DIFF(0, 1)
	EXPECT_DIFF(0, 2)
	EXPECT_DIFF(0, 3)
	EXPECT_EQ(toto.size(), 6);
	EXPECT_DIFF(0, 0)
})

// TEST_SUITE(Vector, Capacity, {
// 	TEST_CASE_RUN(Capacity, AccurateReturn)
// 	TEST_CASE_RUN(Capacity, MemoryClean)
// })

int main( int ac, char **av )
{
	// TESTABLE(Vector)
	// (*(g_test_cases["Vector"]["Capacity"].front().m_run))();
	// TEST_SUITE_RUN(Vector, Capacity)
	TESTABLE_RUN(Vector)
	return 0;
}
