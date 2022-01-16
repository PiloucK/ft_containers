#include "myUnitTest.hpp"

TEST_CASE(Map, Access, Size, {
	{
		typedef MAP<Aware<int> COMMA Aware<double> > M;
		M m;

		ASSERT(m.size() == 0);

		m.insert(M::value_type(2, 1.5));
		ASSERT(m.size() == 1);

		m.insert(M::value_type(1, 1.5));
		ASSERT(m.size() == 2);

		m.insert(M::value_type(3, 1.5));
		ASSERT(m.size() == 3);

		m.erase(m.begin());
		ASSERT(m.size() == 2);

		m.erase(m.begin());
		ASSERT(m.size() == 1);

		m.erase(m.begin());
		ASSERT(m.size() == 0);

	} ASSERT_AWARENESS
	
})
