#include "myUnitTest.hpp"

TEST_CASE(Map, Capacity, Count, {
	{
		typedef MAP<int COMMA Aware<double> > M;
		typedef M::value_type V;
		typedef M::size_type R;

		V ar[] = {
			V(5, 5) COMMA
			V(6, 6) COMMA
			V(7, 7) COMMA
			V(8, 8) COMMA
			V(9, 9) COMMA
			V(10, 10) COMMA
			V(11, 11) COMMA
			V(12, 12) };

		const M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		R r = m.count(5);
		ASSERT(r == 1);

		r = m.count(6);
		ASSERT(r == 1);

		r = m.count(7);
		ASSERT(r == 1);

		r = m.count(8);
		ASSERT(r == 1);

		r = m.count(9);
		ASSERT(r == 1);

		r = m.count(10);
		ASSERT(r == 1);

		r = m.count(11);
		ASSERT(r == 1);

		r = m.count(12);
		ASSERT(r == 1);

		r = m.count(4);
		ASSERT(r == 0);
	} ASSERT_AWARENESS
})
