#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, Clear, {
	{
		typedef MAP<Aware<int> COMMA Aware<double> > M;
		typedef PAIR<Aware<int> COMMA Aware<double> > P;
		P ar[] = {
			P(2, 2.5) COMMA
			P(3, 3.5) COMMA
			P(4, 4.5) COMMA
			P(1, 1.5) COMMA
			P(5, 5.5) COMMA
			P(6, 6.5) COMMA
			P(7, 7.5) COMMA
			P(8, 8.5)};

		M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(m.size() == 8);
		ASSERT_NOEXCEPT(m.clear());

		m.clear();
		ASSERT(m.size() == 0);
	} ASSERT_AWARENESS
})
