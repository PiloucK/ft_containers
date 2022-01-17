#include "myUnitTest.hpp"

TEST_CASE(Map, Operations, EqualRange, {

	typedef MAP<int COMMA Aware<double> > M;
	typedef M::value_type V;

	{
		typedef PAIR<M::iterator COMMA M::iterator> R;

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

		R r = m.equal_range(5);
		ASSERT(r.first == ITER_PLUS(m.begin(), 0));
		ASSERT(r.second == ITER_PLUS(m.begin(), 1));

		r = m.equal_range(7);
		ASSERT(r.first == ITER_PLUS(m.begin(), 1));
		ASSERT(r.second == ITER_PLUS(m.begin(), 2));

		r = m.equal_range(9);
		ASSERT(r.first == ITER_PLUS(m.begin(), 2));
		ASSERT(r.second == ITER_PLUS(m.begin(), 3));

		r = m.equal_range(11);
		ASSERT(r.first == ITER_PLUS(m.begin(), 3));
		ASSERT(r.second == ITER_PLUS(m.begin(), 4));

		r = m.equal_range(13);
		ASSERT(r.first == ITER_PLUS(m.begin(), 4));
		ASSERT(r.second == ITER_PLUS(m.begin(), 5));

		r = m.equal_range(15);
		ASSERT(r.first == ITER_PLUS(m.begin(), 5));
		ASSERT(r.second == ITER_PLUS(m.begin(), 6));

		r = m.equal_range(17);
		ASSERT(r.first == ITER_PLUS(m.begin(), 6));
		ASSERT(r.second == ITER_PLUS(m.begin(), 7));

		r = m.equal_range(19);
		ASSERT(r.first == ITER_PLUS(m.begin(), 7));
		ASSERT(r.second == ITER_PLUS(m.begin(), 8));

		r = m.equal_range(4);
		ASSERT(r.first == ITER_PLUS(m.begin(), 0));
		ASSERT(r.second == ITER_PLUS(m.begin(), 0));

		r = m.equal_range(6);
// r.first.m_node->print((m.end().m_node));
		ASSERT(r.first == ITER_PLUS(m.begin(), 1));
		ASSERT(r.second == ITER_PLUS(m.begin(), 1));

		r = m.equal_range(8);
		ASSERT(r.first == ITER_PLUS(m.begin(), 2));
		ASSERT(r.second == ITER_PLUS(m.begin(), 2));

		r = m.equal_range(10);
		ASSERT(r.first == ITER_PLUS(m.begin(), 3));
		ASSERT(r.second == ITER_PLUS(m.begin(), 3));

		r = m.equal_range(12);
		ASSERT(r.first == ITER_PLUS(m.begin(), 4));
		ASSERT(r.second == ITER_PLUS(m.begin(), 4));

		r = m.equal_range(14);
		ASSERT(r.first == ITER_PLUS(m.begin(), 5));
		ASSERT(r.second == ITER_PLUS(m.begin(), 5));

		r = m.equal_range(16);
		ASSERT(r.first == ITER_PLUS(m.begin(), 6));
		ASSERT(r.second == ITER_PLUS(m.begin(), 6));

		r = m.equal_range(18);
		ASSERT(r.first == ITER_PLUS(m.begin(), 7));
		ASSERT(r.second == ITER_PLUS(m.begin(), 7));

		r = m.equal_range(20);
		ASSERT(r.first == ITER_PLUS(m.begin(), 8));
		ASSERT(r.second == ITER_PLUS(m.begin(), 8));
	} ASSERT_AWARENESS

	{
		typedef PAIR<Aware<M::const_iterator> COMMA Aware<M::const_iterator> > R;

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

		R r = m.equal_range(5);
		ASSERT(r.first == ITER_PLUS(m.begin(), 0));
		ASSERT(r.second == ITER_PLUS(m.begin(), 1));

		r = m.equal_range(7);
		ASSERT(r.first == ITER_PLUS(m.begin(), 1));
		ASSERT(r.second == ITER_PLUS(m.begin(), 2));

		r = m.equal_range(9);
		ASSERT(r.first == ITER_PLUS(m.begin(), 2));
		ASSERT(r.second == ITER_PLUS(m.begin(), 3));

		r = m.equal_range(11);
		ASSERT(r.first == ITER_PLUS(m.begin(), 3));
		ASSERT(r.second == ITER_PLUS(m.begin(), 4));

		r = m.equal_range(13);
		ASSERT(r.first == ITER_PLUS(m.begin(), 4));
		ASSERT(r.second == ITER_PLUS(m.begin(), 5));

		r = m.equal_range(15);
		ASSERT(r.first == ITER_PLUS(m.begin(), 5));
		ASSERT(r.second == ITER_PLUS(m.begin(), 6));

		r = m.equal_range(17);
		ASSERT(r.first == ITER_PLUS(m.begin(), 6));
		ASSERT(r.second == ITER_PLUS(m.begin(), 7));

		r = m.equal_range(19);
		ASSERT(r.first == ITER_PLUS(m.begin(), 7));
		ASSERT(r.second == ITER_PLUS(m.begin(), 8));

		r = m.equal_range(4);
		ASSERT(r.first == ITER_PLUS(m.begin(), 0));
		ASSERT(r.second == ITER_PLUS(m.begin(), 0));

		r = m.equal_range(6);
		ASSERT(r.first == ITER_PLUS(m.begin(), 1));
		ASSERT(r.second == ITER_PLUS(m.begin(), 1));

		r = m.equal_range(8);
		ASSERT(r.first == ITER_PLUS(m.begin(), 2));
		ASSERT(r.second == ITER_PLUS(m.begin(), 2));

		r = m.equal_range(10);
		ASSERT(r.first == ITER_PLUS(m.begin(), 3));
		ASSERT(r.second == ITER_PLUS(m.begin(), 3));

		r = m.equal_range(12);
		ASSERT(r.first == ITER_PLUS(m.begin(), 4));
		ASSERT(r.second == ITER_PLUS(m.begin(), 4));

		r = m.equal_range(14);
		ASSERT(r.first == ITER_PLUS(m.begin(), 5));
		ASSERT(r.second == ITER_PLUS(m.begin(), 5));

		r = m.equal_range(16);
		ASSERT(r.first == ITER_PLUS(m.begin(), 6));
		ASSERT(r.second == ITER_PLUS(m.begin(), 6));

		r = m.equal_range(18);
		ASSERT(r.first == ITER_PLUS(m.begin(), 7));
		ASSERT(r.second == ITER_PLUS(m.begin(), 7));

		r = m.equal_range(20);
		ASSERT(r.first == ITER_PLUS(m.begin(), 8));
		ASSERT(r.second == ITER_PLUS(m.begin(), 8));
	} ASSERT_AWARENESS
})
