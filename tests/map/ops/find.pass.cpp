#include "myUnitTest.hpp"

TEST_CASE(Map, Operations, Find, {
	typedef MAP<int COMMA Aware<double> > M;
	typedef M::value_type V;

	{
		typedef M::iterator R;

		V ar[] = {
			V(5, 5) COMMA
			V(6, 6) COMMA
			V(7, 7) COMMA
			V(8, 8) COMMA
			V(9, 9) COMMA
			V(10, 10) COMMA
			V(11, 11) COMMA
			V(12, 12) };

		M m(ar, ar + sizeof(ar) / sizeof(ar[0]));

		R r = m.find(5);
		ASSERT(r == m.begin());

		r = m.find(6);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.find(7);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.find(8);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.find(9);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.find(10);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.find(11);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.find(12);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.find(4);
		ASSERT(r == ITER_PLUS(m.begin(), 8));
	}

	{
		typedef M::const_iterator R;

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

		R r = m.find(5);
		ASSERT(r == m.begin());

		r = m.find(6);
		ASSERT(r == ITER_PLUS(m.begin(), 1));

		r = m.find(7);
		ASSERT(r == ITER_PLUS(m.begin(), 2));

		r = m.find(8);
		ASSERT(r == ITER_PLUS(m.begin(), 3));

		r = m.find(9);
		ASSERT(r == ITER_PLUS(m.begin(), 4));

		r = m.find(10);
		ASSERT(r == ITER_PLUS(m.begin(), 5));

		r = m.find(11);
		ASSERT(r == ITER_PLUS(m.begin(), 6));

		r = m.find(12);
		ASSERT(r == ITER_PLUS(m.begin(), 7));

		r = m.find(4);
		ASSERT(r == ITER_PLUS(m.begin(), 8));
	} ASSERT_AWARENESS
})
