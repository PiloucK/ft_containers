#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, EraseKey, {
	{
		typedef MAP<int COMMA Aware<double> > M;
		typedef PAIR<int COMMA Aware<double> > P;
		typedef M::size_type R;

		P ar[] = {
			P(1, 1.5) COMMA
			P(2, 2.5) COMMA
			P(3, 3.5) COMMA
			P(4, 4.5) COMMA
			P(5, 5.5) COMMA
			P(6, 6.5) COMMA
			P(7, 7.5) COMMA
			P(8, 8.5) };

		M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(m.size() == 8);

		R s = m.erase(9);
		ASSERT(s == 0);
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

		s = m.erase(4);
		ASSERT(m.size() == 7);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 1);
		ASSERT(m.begin()->second == 1.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 2);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 4)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 4)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 5)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 5)->second == 7.5);
		ASSERT(ITER_PLUS(m.begin(), 6)->first == 8);
		ASSERT(ITER_PLUS(m.begin(), 6)->second == 8.5);

		s = m.erase(1);
		ASSERT(m.size() == 6);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 2);
		ASSERT(m.begin()->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 4)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 4)->second == 7.5);
		ASSERT(ITER_PLUS(m.begin(), 5)->first == 8);
		ASSERT(ITER_PLUS(m.begin(), 5)->second == 8.5);

		s = m.erase(8);
		ASSERT(m.size() == 5);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 2);
		ASSERT(m.begin()->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 3);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 3.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 4)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 4)->second == 7.5);

		s = m.erase(3);
		ASSERT(m.size() == 4);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 2);
		ASSERT(m.begin()->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 6);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 6.5);
		ASSERT(ITER_PLUS(m.begin(), 3)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 3)->second == 7.5);

		s = m.erase(6);
		ASSERT(m.size() == 3);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 2);
		ASSERT(m.begin()->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 5.5);
		ASSERT(ITER_PLUS(m.begin(), 2)->first == 7);
		ASSERT(ITER_PLUS(m.begin(), 2)->second == 7.5);

		s = m.erase(7);
		ASSERT(m.size() == 2);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 2);
		ASSERT(m.begin()->second == 2.5);
		ASSERT(ITER_PLUS(m.begin(), 1)->first == 5);
		ASSERT(ITER_PLUS(m.begin(), 1)->second == 5.5);

		s = m.erase(2);
		ASSERT(m.size() == 1);
		ASSERT(s == 1);
		ASSERT(m.begin()->first == 5);
		ASSERT(m.begin()->second == 5.5);

		s = m.erase(5);
		ASSERT(m.size() == 0);
		ASSERT(s == 1);
	} ASSERT_AWARENESS
})
