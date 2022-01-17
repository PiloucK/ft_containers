#include "myUnitTest.hpp"

TEST_CASE(Map, Modifiers, Swap, {
	typedef MAP<Aware<int> COMMA Aware<double> > M;
	typedef M::value_type V;

	{
		M m1;
		M m2;
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	} ASSERT_AWARENESS

	{
		V ar2[] = {
			V(5, 5) COMMA
			V(6, 6) COMMA
			V(7, 7) COMMA
			V(8, 8) COMMA
			V(9, 9) COMMA
			V(10, 10) COMMA
			V(11, 11) COMMA
			V(12, 12) };

		M m1;
		M m2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	} ASSERT_AWARENESS

	{
		V ar1[] = {
			V(1, 1) COMMA
			V(2, 2) COMMA
			V(3, 3) COMMA
			V(4, 4) };

		M m1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));

		M m2;
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	} ASSERT_AWARENESS

	{
		V ar1[] = {
			V(1, 1) COMMA
			V(2, 2) COMMA
			V(3, 3) COMMA
			V(4, 4) };

		V ar2[] = {
			V(5, 5) COMMA
			V(6, 6) COMMA
			V(7, 7) COMMA
			V(8, 8) COMMA
			V(9, 9) COMMA
			V(10, 10) COMMA
			V(11, 11) COMMA
			V(12, 12) };

		M m1(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
		M m2(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
		M m1_save = m1;
		M m2_save = m2;

		m1.swap(m2);
		ASSERT(m1 == m2_save);
		ASSERT(m2 == m1_save);
	} ASSERT_AWARENESS
})
