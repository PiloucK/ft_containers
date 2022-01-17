#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, EraseIteratorRange, {
	{
		typedef MAP<int COMMA Aware<double> > M;
		typedef PAIR<int COMMA Aware<double> > P;

		P ar[] = {
			P(1, 1.5) COMMA
			P(2, 2.5) COMMA
			P(3, 3.5) COMMA
			P(4, 4.5) COMMA
			P(5, 5.5) COMMA
			P(6, 6.5) COMMA
			P(7, 7.5) COMMA
			P(8, 8.5)};

		M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(m.size() == 8);

		m.erase(m.begin(), m.begin());
		ASSERT(m.size() == 8);
		ASSERT(m.begin()->first == 1);
		ASSERT(m.begin()->second == 1.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 2);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 4);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 4.5);
		ASSERT(ITER_PLUS(m.begin(), 4)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 4)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 5)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 5)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 6)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 6)->second == 7.5);
		ASSERT(ITER_PLUS(m.begin(), 7)->first == 8);
		ASSERT(ITER_PLUS(m.begin(), 7)->second == 8.5);

		m.erase(m.begin(), ITER_PLUS(m.begin(), 2));
		ASSERT(m.size() == 6);
		ASSERT(ITER_PLUS(m.begin(), 0)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 0)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 4);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 4.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 4)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 4)->second == 7.5);
		ASSERT(ITER_PLUS(m.begin(), 5)->first == 8);
		ASSERT(ITER_PLUS(m.begin(), 5)->second == 8.5);

		m.erase(ITER_PLUS(m.begin(), 2), ITER_PLUS(m.begin(), 6));
		ASSERT(m.size() == 2);
		ASSERT(ITER_PLUS(m.begin(), 0)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 0)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 4);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 4.5);

		m.erase(m.begin(), m.end());
		ASSERT(m.size() == 0);
		ASSERT(m.begin() == m.end());
	} ASSERT_AWARENESS
})
