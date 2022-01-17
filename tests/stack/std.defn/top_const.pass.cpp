#include "myUnitTest.hpp"

TEST_CASE(Stack, MemberMethod, TopConst, {
	{
		STACK<Aware<int> > stack;

		ASSERT(stack.size() == 0);

		stack.push(1);
		stack.push(2);
		stack.push(3);
		const STACK<Aware<int> > & cstack = stack;
		const Aware<int> & ctop = cstack.top();
		ASSERT(ctop == 3);
	} ASSERT_AWARENESS
})
