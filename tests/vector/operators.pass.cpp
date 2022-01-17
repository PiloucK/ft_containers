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

	{
		VECTOR<int> foo(3, 100);
		VECTOR<int> bar(3, 200);

		ASSERT((foo == bar) == false);
		ASSERT((foo != bar) == true);
		ASSERT((foo < bar) == true);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == false);
	}

	{
		VECTOR<int> foo(3, 100);
		VECTOR<int> bar(5, 200);

		ASSERT((foo == bar) == false);
		ASSERT((foo != bar) == true);
		ASSERT((foo < bar) == true);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == false);
	}

	{
		VECTOR<int> foo(3, 200);
		VECTOR<int> bar(3, 200);

		ASSERT((foo == bar) == true);
		ASSERT((foo != bar) == false);
		ASSERT((foo < bar) == false);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == true);
	}

	{
		VECTOR<int> foo;
		VECTOR<int> bar(2, 200);

		ASSERT((foo == bar) == false);
		ASSERT((foo != bar) == true);
		ASSERT((foo < bar) == true);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == false);
	}

	{
		VECTOR<int> foo;
		VECTOR<int> bar;

		ASSERT((foo == bar) == true);
		ASSERT((foo != bar) == false);
		ASSERT((foo < bar) == false);
		ASSERT((foo > bar) == false);
		ASSERT((foo <= bar) == true);
		ASSERT((foo >= bar) == true);
	}
})
