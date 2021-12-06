#include "myUnitTest.hpp"

void
test(VECTOR<Aware<int> > &v, std::stringstream & output_string, int & test_passed, int & test_failed)
{
	v.assign(5, Aware<int>(6));
	ASSERT(v.size() == 5);

	for (VECTOR<Aware<int> >::iterator it = v.begin(); it < v.end(); it++) {
		ASSERT(*it == Aware<int>(6));
	}
}

TEST_CASE(Vector, Assign, ValueModification, {
	{
		typedef VECTOR<Aware<int> > V;
		V d1;
		V d2;

		d2.reserve(10);

		test(d1, output_string, test_passed, test_failed);
		test(d2, output_string, test_passed, test_failed);
	} ASSERT_AWARENESS
})
