#include "myUnitTest.hpp"
#include "Vector.hpp"

template<class C>
	void
	test(typename C::size_type n, std::stringstream & output_string, int & test_passed, int & test_failed)
	{
		C c(n);

		std::cout << "--------------------------Count = " << aware_count << "\n";
		ASSERT(c.size() == n);
		std::cout << "--------------------------Count = " << aware_count << "\n";
	}

TEST_CASE(Vector, Constructor, SizeOnlyParam, {
	test<VECTOR<int> >(50, output_string, test_passed, test_failed);
	std::cout << "--------------------------Count = " << aware_count << "\n";
	test<VECTOR<Aware<int> > >(500, output_string, test_passed, test_failed);
	std::cout << "--------------------------Count = " << aware_count << "\n";

	// {
	// 	VECTOR<Aware<int> > C(500);
	// 	ASSERT(C.size() == 500);
	// }
	ASSERT_AWARENESS
})

int main ()
{
	
	{
		test<ft::Vector<Aware<int> > >(500, output_string, test_passed, test_failed);
	}
	std::cout << aware_count;
	return 0;
}
