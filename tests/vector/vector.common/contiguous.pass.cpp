// #include "myUnitTest.hpp"

// template<class C>
// 	void
// 	test_contiguous(const C &c, std::stringstream & output_string, int & test_passed, int & test_failed)
// 	{
// 		for (size_t i = 0; i < c.size(); ++i)
// 			ASSERT(*(c.begin() + static_cast<typename C::difference_type>(i)) == *(std::addressof(*c.begin()) + i));
// 	}

// TEST_CASE(Vector, Memory, ContiguousAllocation, {
// 	{
// 		typedef Aware<int> T;
// 		typedef VECTOR<T> C;

// 		test_contiguous(C(), output_string, test_passed, test_failed);
// 		test_contiguous(C(3, T(5)), output_string, test_passed, test_failed);
// 	} ASSERT_AWARENESS
// })
