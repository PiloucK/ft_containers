// #include "myUnitTest.hpp"

// TEST_CASE(Vector, Modifiers, InsertWithIteratorSizeAndValueParam, {
// 	{
// 		VECTOR<Aware<int> > v(100);

// 		v.insert(v.begin() + 10, 5, 1);
// 		ASSERT(v.size() == 105);

// 		int j;
// 		for (j = 0; j < 10; ++j)
// 			ASSERT(v[j] == 0);

// 		for (; j < 15; ++j)
// 			ASSERT(v[j] == 1);

// 		for (++j; j < 105; ++j)
// 			ASSERT(v[j] == 0);
// 	} ASSERT_AWARENESS

// 	{
// 		VECTOR<Aware<int> > v(100);

// 		while (v.size() < v.capacity())
// 			v.push_back(0);

// 		size_t sz = v.size();
// 		v.insert(v.begin() + 10, 5, 1);
// 		ASSERT(v.size() == sz + 5);

// 		size_t j;
// 		for (j = 0; j < 10; ++j)
// 			ASSERT(v[j] == 0);

// 		for (; j < 15; ++j)
// 			ASSERT(v[j] == 1);

// 		for (++j; j < v.size(); ++j)
// 			ASSERT(v[j] == 0);
// 	} ASSERT_AWARENESS

// 	{
// 		VECTOR<Aware<int> > v(100);

// 		v.reserve(128);

// 		size_t sz = v.size();
// 		v.insert(v.begin() + 10, 5, 1);
// 		ASSERT(v.size() == sz + 5);

// 		size_t j;
// 		for (j = 0; j < 10; ++j)
// 			ASSERT(v[j] == 0);

// 		for (; j < 15; ++j)
// 			ASSERT(v[j] == 1);

// 		for (++j; j < v.size(); ++j)
// 			ASSERT(v[j] == 0);
// 	} ASSERT_AWARENESS
// })
