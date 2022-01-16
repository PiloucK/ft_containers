#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, Size, {
	{
		STACK<Aware<int> > stack;

		ASSERT(stack.size() == 0);

		stack.push(1);
		ASSERT(stack.size() == 1);

		stack.pop();
		ASSERT(stack.size() == 0);

	} ASSERT_AWARENESS
})
