#include "myUnitTest.hpp"

TEST_CASE(Map, Access, Empty, {
	{
		typedef MAP<Aware<int> COMMA Aware<double> > M;
		M m;

		ASSERT(m.empty());
		m.insert(M::value_type(1, 1.5));
		ASSERT(!m.empty());

		m.insert(M::value_type(2, 4));
		m.clear();
		ASSERT(m.empty());
	} ASSERT_AWARENESS
})
