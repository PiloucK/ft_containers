#include "myUnitTest.hpp"

template<class C>
	void
	test(typename C::size_type n)
	{
		C c(n);

		ASSERT(c.size() == n);
	}

TEST_CASE(Vector, Constructor, SizeOnlyParam, {
	test<VECTOR<int> >(50);
	test<VECTOR<Aware<int> > >(500);

	ASSERT_AWARENESS
})
