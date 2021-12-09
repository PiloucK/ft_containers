#include "myUnitTest.hpp"

TEST_CASE(Vector, Constructor, Default, {
	{
		VECTOR<Aware<int> > v;

		ASSERT(v.empty());
	} ASSERT_AWARENESS
})
