#include "myUnitTest.hpp"

TEST_CASE(Vector, CopyConstructor, ObjectConsistency, {
	{
		VECTOR<Aware<int> > l(3, Aware<int>(2));
		VECTOR<Aware<int> > l2(l);

		l2 = l;

		ASSERT(l2 == l);
	} ASSERT_AWARENESS

	{
		VECTOR<Aware<int> > l(3, Aware<int>(2));
		VECTOR<Aware<int> > l2(l);

		l2 = l;

		ASSERT(l2 == l);
	} ASSERT_AWARENESS
})
