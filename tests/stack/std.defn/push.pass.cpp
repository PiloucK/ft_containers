#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, Push, {
	{
		STACK<Aware<int> > q;

		q.push(1);
		ASSERT(q.size() == 1);
		ASSERT(q.top() == 1);

		q.push(2);
		ASSERT(q.size() == 2);
		ASSERT(q.top() == 2);

		q.push(3);
		ASSERT(q.size() == 3);
		ASSERT(q.top() == 3);
	} ASSERT_AWARENESS
})
