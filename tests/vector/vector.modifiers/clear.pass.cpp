#include "myUnitTest.hpp"

TEST_CASE(Vector, Modifiers, Clear, {
	{
		Aware<int> a[3];
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;

		VECTOR<Aware<int> > c(a, a + 3);

		c.clear();
		ASSERT(c.empty())
	} ASSERT_AWARENESS
})
