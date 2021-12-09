// #include "myUnitTest.hpp"

// TEST_CASE(Vector, Modifiers, EraseReturnValue, {
// 	{
// 		VECTOR<Aware<int> > l1;
// 		l1.push_back(1);
// 		l1.push_back(2);
// 		l1.push_back(3);

// 		VECTOR<Aware<int> >::iterator i = l1.begin();
// 		++i;
// 		VECTOR<Aware<int> >::iterator j = l1.erase(i);
// 		ASSERT(l1.size() == 2);
// 		ASSERT(*j == 3);
// 		ASSERT(*l1.begin() == 1);
// 		ASSERT(*(l1.begin() + 1) == 3);

// 		j = l1.erase(j);
// 		ASSERT(j == l1.end());
// 		ASSERT(l1.size() == 1);
// 		ASSERT(*l1.begin() == 1);

// 		j = l1.erase(l1.begin());
// 		ASSERT(j == l1.end());
// 		ASSERT(l1.size() == 0);
// 	} ASSERT_AWARENESS
// })
