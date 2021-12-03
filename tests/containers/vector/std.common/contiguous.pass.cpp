#include "myUnitTest.hpp"

template<class C>
	void
	test_contiguous(const C &c)
	{
		for (size_t i = 0; i < c.size(); ++i)
			ASSERT(*(c.begin() + static_cast<typename C::difference_type>(i)) == *(addressof(*c.begin()) + i));
	}

TEST_CASE(Vector, Memory, ContiguousAllocation, {
	{
		typedef Aware<int> T;
		typedef VECTOR<T> C;

		test_contiguous(C());
		test_contiguous(C(3, T(5)));
	} ASSERT_AWARENESS
})
