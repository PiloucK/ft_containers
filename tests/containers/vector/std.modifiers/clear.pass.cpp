#include "myUnitTest.hpp"

TEST_CASE(Vector, Modifiers, Clear, {
	{
		Aware<int> a[] = { 1, 2, 3 };

		VECTOR<Aware<int> > c(a, a + 3);

		c.clear();
		ASSERT(c.empty());
	} ASSERT_AWARENESS
})
