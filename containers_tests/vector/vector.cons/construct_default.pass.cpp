#include "myUnitTest.hpp"

// Requirements
//  - default ctor
//  - empty()

TEST_CASE(Vector, Constructor, Default, {
	{
		VECTOR<Aware<int> > v;

		ASSERT(v.empty());
	} ASSERT_AWARENESS
})
