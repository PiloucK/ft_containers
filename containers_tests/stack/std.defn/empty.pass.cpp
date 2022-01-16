#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, Empty, {
	{
	    STACK<Aware<int> > stack;
	    ASSERT(stack.empty());

	    stack.push(1);
	    ASSERT(!stack.empty());

	    stack.pop();
	    ASSERT(stack.empty());
	}
})
