#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, Pop, {
	{
		STACK<Aware<int> > stack;

		ASSERT(stack.size() == 0);

		stack.push(1);
		stack.push(2);
		stack.push(3);
		ASSERT(stack.size() == 3);
		ASSERT(stack.top() == 3);

		stack.pop();
		ASSERT(stack.size() == 2);
		ASSERT(stack.top() == 2);

		stack.pop();
		ASSERT(stack.size() == 1);
		ASSERT(stack.top() == 1);

		stack.pop();
		ASSERT(stack.size() == 0);
	} ASSERT_AWARENESS
})
