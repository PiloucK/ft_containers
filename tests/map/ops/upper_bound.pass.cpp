#include "myUnitTest.hpp"

TEST_CASE(Map, Operations, UpperBound, {
	typedef MAP<int COMMA Aware<double> > M;
	typedef M::value_type V;

	{
		typedef M::iterator R;

		V ar[] = {
			V(5, 5) COMMA
			V(7, 6) COMMA
			V(9, 7) COMMA
			V(11, 8) COMMA
			V(13, 9) COMMA
			V(15, 10) COMMA
			V(17, 11) COMMA
			V(19, 12) };

		M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		R r = m.upper_bound(5);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.upper_bound(7);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.upper_bound(9);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.upper_bound(11);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.upper_bound(13);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.upper_bound(15);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.upper_bound(17);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.upper_bound(19);
		ASSERT(r == ITER_PLUS(m.begin(), 8));

		r = m.upper_bound(4);
		ASSERT(r == ITER_PLUS(m.begin(), 0));

		r = m.upper_bound(6);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.upper_bound(8);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.upper_bound(10);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.upper_bound(12);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.upper_bound(14);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.upper_bound(16);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.upper_bound(18);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.upper_bound(20);
		ASSERT(r == ITER_PLUS(m.begin(), 8));
	} ASSERT_AWARENESS

	{
		typedef M::const_iterator R;

		V ar[] = {
			V(5, 5) COMMA
			V(7, 6) COMMA
			V(9, 7) COMMA
			V(11, 8) COMMA
			V(13, 9) COMMA
			V(15, 10) COMMA
			V(17, 11) COMMA
			V(19, 12) };

		const M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		R r = m.upper_bound(5);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.upper_bound(7);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.upper_bound(9);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.upper_bound(11);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.upper_bound(13);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.upper_bound(15);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.upper_bound(17);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.upper_bound(19);
		ASSERT(r == ITER_PLUS(m.begin(), 8));

		r = m.upper_bound(4);
		ASSERT(r == ITER_PLUS(m.begin(), 0));

		r = m.upper_bound(6);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.upper_bound(8);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.upper_bound(10);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.upper_bound(12);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.upper_bound(14);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.upper_bound(16);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.upper_bound(18);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.upper_bound(20);
		ASSERT(r == ITER_PLUS(m.begin(), 8));
	} ASSERT_AWARENESS
})
