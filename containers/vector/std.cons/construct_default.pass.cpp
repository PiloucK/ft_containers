#include "myUnitTest.hpp"

TEST_CASE(Vector, Constuctor, Default, {
	{
		VECTOR<Aware<int> > v;

		ASSERT(v.empty());
	}
})
