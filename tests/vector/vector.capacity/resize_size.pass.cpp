#include "myUnitTest.hpp"

TEST_CASE(Vector, Resize, SizeVsCapacity, {
	{
		VECTOR<Aware<int> > v(100);

		v.resize(50);
		ASSERT(v.size() == 50);
		ASSERT(v.capacity() == 100);

		v.resize(200);
		ASSERT(v.size() == 200);
		ASSERT(v.capacity() >= 200);
	} ASSERT_AWARENESS
})
