#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, Top, {
	{
		STACK<Aware<int> > stack;

		ASSERT(stack.size() == 0);

		stack.push(1);
		stack.push(2);
		stack.push(3);
		Aware<int> & top = stack.top();
		ASSERT(top == 3);
	} ASSERT_AWARENESS
})
