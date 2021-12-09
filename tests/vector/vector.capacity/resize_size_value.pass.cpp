// #include "myUnitTest.hpp"

// TEST_CASE(Vector, Resize, WithValues, {
// 	{
// 		VECTOR<Aware<int> > v(100);

// 		v.resize(50, 1);
// 		ASSERT(v.size() == 50);
// 		ASSERT(v.capacity() == 100);
// 		ASSERT(v == VECTOR<Aware<int> >(50));

// 		v.resize(200, 1);
// 		ASSERT(v.size() == 200);
// 		ASSERT(v.capacity() >= 200);

// 		for (unsigned i = 0; i < 50; ++i)
// 			ASSERT(v[i] == 0);

// 		for (unsigned i = 50; i < 200; ++i)
// 			ASSERT(v[i] == 1);
// 	} ASSERT_AWARENESS
// })
