// #include "myUnitTest.hpp"

// TEST_CASE(Vector, Size, AccurateReturn, {
// 	{
// 		typedef VECTOR<int> C;
// 		C c;

// 		ASSERT_NOEXCEPT(c.size());

// 		ASSERT(c.size() == 0);

// 		c.push_back(C::value_type(2));
// 		ASSERT(c.size() == 1);

// 		c.push_back(C::value_type(1));
// 		ASSERT(c.size() == 2);

// 		c.push_back(C::value_type(3));
// 		ASSERT(c.size() == 3);

// 		c.erase(c.begin());
// 		ASSERT(c.size() == 2);

// 		c.erase(c.begin());
// 		ASSERT(c.size() == 1);

// 		c.erase(c.begin());
// 		ASSERT(c.size() == 0);
// 	} ASSERT_AWARENESS
// })
