#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, InsertIteratorRange,  {
	{
		typedef MAP<int COMMA Aware<double> > M;
		typedef PAIR<int COMMA Aware<double> > P;

		P ar[] = {
			P(1, 1) COMMA
			P(1, 1.5) COMMA
			P(1, 2) COMMA
			P(2, 1) COMMA
			P(2, 1.5) COMMA
			P(2, 2) COMMA
			P(3, 1) COMMA
			P(3, 1.5) COMMA
			P(3, 2) };

		M m;

		m.insert(ar, ar + sizeof(ar) / sizeof(ar[0]));
		ASSERT(m.size() == 3);
		ASSERT(m.begin()->first == 1);
		ASSERT(m.begin()->second == 1);
		ASSERT((++(m.begin()))->first == 2);
		ASSERT((++(m.begin()))->second == 1);
		M::iterator it = m.begin();
		++it;
		++it;
		ASSERT(it->first == 3);
		ASSERT(it->second == 1);
	} ASSERT_AWARENESS
})
