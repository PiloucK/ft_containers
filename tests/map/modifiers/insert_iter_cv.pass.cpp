#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, InsertIteratorHinted, {
	{
		typedef MAP<int COMMA Aware<double> > M;
		typedef M::iterator R;
		typedef M::value_type VT;

		M m;

		const VT v1(2, 2.5);
		R r = m.insert(m.end(), v1);
		ASSERT(r == m.begin());
		ASSERT(m.size() == 1);
		ASSERT(r->first == 2);
		ASSERT(r->second == 2.5);

		const VT v2(1, 1.5);
		r = m.insert(m.end(), v2);
		ASSERT(r == m.begin());
		ASSERT(m.size() == 2);
		ASSERT(r->first == 1);
		ASSERT(r->second == 1.5);

		const VT v3(3, 3.5);
		r = m.insert(m.end(), v3);
		ASSERT(r == --(m.end()));
		ASSERT(m.size() == 3);
		ASSERT(r->first == 3);
		ASSERT(r->second == 3.5);

		const VT v4(3, 4.5);
		r = m.insert(m.end(), v4);
		ASSERT(r == --(m.end()));
		ASSERT(m.size() == 3);
		ASSERT(r->first == 3);
		ASSERT(r->second == 3.5);
	} ASSERT_AWARENESS
})
