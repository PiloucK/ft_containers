#include "myUnitTest.hpp"

TEST_CASE(Vector, Modifiers, InsertWithIteratorAndValueParam, {
	{
		VECTOR<int> v(100);

		VECTOR<int>::iterator i = v.insert(v.begin() + 10, 1);
		ASSERT(v.size() == 101);
		ASSERT(i == v.begin() + 10);

		int j;
		for (j = 0; j < 10; ++j)
			ASSERT(v[j] == 0);

		ASSERT(v[j] == 1);

		for (++j; j < 101; ++j)
			ASSERT(v[j] == 0);
	} ASSERT_AWARENESS

	{
		VECTOR<int> v(100);

		while (v.size() < v.capacity())
			v.push_back(0);
		size_t sz = v.size();
		VECTOR<int>::iterator i = v.insert(v.begin() + 10, 1);
		ASSERT(v.size() == sz + 1);
		ASSERT(i == v.begin() + 10);

		std::size_t j;
		for (j = 0; j < 10; ++j)
			ASSERT(v[j] == 0);

		ASSERT(v[j] == 1);

		for (++j; j < v.size(); ++j)
			ASSERT(v[j] == 0);
	} ASSERT_AWARENESS

	{
		VECTOR<int> v(100);

		while (v.size() < v.capacity())
			v.push_back(0);
		v.pop_back();
		v.pop_back();

		size_t sz = v.size();
		VECTOR<int>::iterator i = v.insert(v.begin() + 10, 1);
		ASSERT(v.size() == sz + 1);
		ASSERT(i == v.begin() + 10);

		std::size_t j;
		for (j = 0; j < 10; ++j)
			ASSERT(v[j] == 0);

		ASSERT(v[j] == 1);

		for (++j; j < v.size(); ++j)
			ASSERT(v[j] == 0);
	} ASSERT_AWARENESS
})
