#include "myUnitTest.hpp"

TEST_CASE(Vector, ComparisonOperator, AccurateReturn, {
	{
		VECTOR<int> foo(3, 100);
		VECTOR<int> bar(2, 200);

		ASSERT((foo == bar) == false);
		ASSERT((foo != bar) == true);
		ASSERT((foo < bar) == true);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == false);
	}
})
