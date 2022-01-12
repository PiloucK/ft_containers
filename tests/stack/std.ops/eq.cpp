#include "myUnitTest.hpp"

template<class C>
	C
	make(int n)
	{
		C c;

		for (int i = 0; i < n; ++i)
			c.push(i);

		return (c);
	}

TEST_CASE(Stack, Operator, Equality, {
	{
		STACK<int> q1 = make<STACK<int> >(5);
		STACK<int> q2 = make<STACK<int> >(10);
		STACK<int> q1_save = q1;
		STACK<int> q2_save = q2;

		ASSERT(q1 == q1_save);
		ASSERT(q1 != q2);
		ASSERT(q2 == q2_save);
	} ASSERT_AWARENESS
})
