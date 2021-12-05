#include "myUnitTest.hpp"

template<class C>
	void
	test(typename C::size_type n, const typename C::value_type &x)
	{
		C c(n, x);
		ASSERT(c.size() == n);

		for (typename C::const_iterator i = c.begin(), e = c.end(); i != e; ++i)
			ASSERT(*i == x);
	}

TEST_CASE(Vector, Constructor, SizeAndValueProvided, {
	test<VECTOR<int> >(50, 3);
	test<VECTOR<Aware<int> > >(50, 5);

	ASSERT_AWARENESSS
})
