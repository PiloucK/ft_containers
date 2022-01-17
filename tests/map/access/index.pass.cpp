#include "myUnitTest.hpp"

TEST_CASE(Map, Access, IndexAccess, {
	{
		typedef PAIR<const int COMMA double> V;
		V ar[] = {
			V(1, 1.5) COMMA
			V(2, 2.5) COMMA
			V(3, 3.5) COMMA
			V(4, 4.5) COMMA
			V(5, 5.5) COMMA
			V(7, 7.5) COMMA
			V(8, 8.5) };

		MAP<int COMMA double> m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		ASSERT(m.size() == 7);
		ASSERT(m[1] == 1.5);
		ASSERT(m.size() == 7);

		m[1] = -1.5;
		ASSERT(m[1] == -1.5);
		ASSERT(m.size() == 7);
		ASSERT(m[6] == 0);
		ASSERT(m.size() == 8);

		m[6] = 6.5;
		ASSERT(m[6] == 6.5);
		ASSERT(m.size() == 8);
	} ASSERT_AWARENESS
})
