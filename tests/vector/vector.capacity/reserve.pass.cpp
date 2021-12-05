#include "myUnitTest.hpp"

TEST_CASE(Vector, ReserveMethod, SizeVsCapacity, {
	{
		VECTOR<int> v;

		v.reserve(10);
		ASSERT(v.capacity() >= 10);
	}

	{
		VECTOR<Aware<int> > v(100);

		ASSERT(v.capacity() == 100);

		v.reserve(50);
		ASSERT(v.size() == 100);
		ASSERT(v.capacity() == 100);

		v.reserve(150);
		ASSERT(v.size() == 100);
		ASSERT(v.capacity() == 150);
	} ASSERT_AWARENESS
})
