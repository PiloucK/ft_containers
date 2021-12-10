#include "myUnitTest.hpp"

template<class C>
	void
	test(typename C::size_type n, std::stringstream & output_string, int & test_passed, int & test_failed)
	{
		C c(n);

		ASSERT(c.size() == n);
	}

TEST_CASE(Vector, Constructor, SizeOnlyParam, {
	test<VECTOR<int> >(50, output_string, test_passed, test_failed);
	test<VECTOR<Aware<int> > >(500, output_string, test_passed, test_failed);

	// {
	// 	VECTOR<Aware<int> > C(500);
	// 	ASSERT(C.size() == 500);
	// }
	ASSERT_AWARENESS
})
