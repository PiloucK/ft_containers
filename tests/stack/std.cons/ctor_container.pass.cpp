#include "myUnitTest.hpp"

template<class C>
	C
	make(int n)
	{
		C c;
		for (int i = 0; i < n; ++i)
			c.push_back(i);

		return (c);
	}

TEST_CASE(Stack, Constructor, UsingVector, {
	{
		VECTOR<int> vector = make<VECTOR<int> >(5);
		STACK<int COMMA VECTOR<int> > stack(vector);

		ASSERT(stack.size() == 5);
		for (std::size_t i = 0; i < vector.size(); ++i)
		{
			ASSERT(stack.top() == vector[vector.size() - i - 1]);
			stack.pop();
		}
	} ASSERT_AWARENESS
})
