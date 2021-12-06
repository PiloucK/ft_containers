#include "myUnitTest.hpp"

static void a1_init(Aware<int> a1[])
{
	a1[0] = 1;
	a1[1] = 3;
	a1[2] = 7;
	a1[3] = 9;
	a1[4] = 10;
}

static void a2_init(Aware<int> a2[])
{
	a2[0] = 0;
	a2[1] = 2;
	a2[2] = 4;
	a2[3] = 5;
	a2[4] = 6;
	a2[5] = 8;
	a2[6] = 11;
}

TEST_CASE(Vector, Special, CompleteSwapTests, {
	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
		VECTOR<Aware<int> > c2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

		swap(c1, c2);

		ASSERT(c1 == VECTOR<Aware<int> >(a2, a2 + sizeof(a2) / sizeof(a2[0])));
		ASSERT(c2 == VECTOR<Aware<int> >(a1, a1 + sizeof(a1) / sizeof(a1[0])));
	} ASSERT_AWARENESS

	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1);
		VECTOR<Aware<int> > c2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

		swap(c1, c2);

		ASSERT(c1 == VECTOR<Aware<int> >(a2, a2 + sizeof(a2) / sizeof(a2[0])));
		ASSERT(c2.empty());
		ASSERT((c2.end() - c2.begin()) == 0);
	} ASSERT_AWARENESS

	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
		VECTOR<Aware<int> > c2(a2, a2);

		swap(c1, c2);

		ASSERT(c1.empty());
		ASSERT((c1.end() - c1.begin()) == 0);
		ASSERT(c2 == VECTOR<Aware<int> >(a1, a1 + sizeof(a1) / sizeof(a1[0])));
	} ASSERT_AWARENESS

	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1);
		VECTOR<Aware<int> > c2(a2, a2);

		swap(c1, c2);

		ASSERT(c1.empty());
		ASSERT((c1.end() - c1.begin()) == 0);
		ASSERT(c2.empty());
		ASSERT((c2.end() - c2.begin()) == 0);
	} ASSERT_AWARENESS

	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
		VECTOR<Aware<int> > c2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

		swap(c1, c2);

		ASSERT((c1 == VECTOR<Aware<int> >(a2, a2 + sizeof(a2) / sizeof(a2[0]))));
		ASSERT((c2 == VECTOR<Aware<int> >(a1, a1 + sizeof(a1) / sizeof(a1[0]))));
	} ASSERT_AWARENESS

	{
		Aware<int> a1[5];
		a1_init(a1);
		Aware<int> a2[7];
		a2_init(a2);

		VECTOR<Aware<int> > c1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
		VECTOR<Aware<int> > c2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

		swap(c1, c2);

		ASSERT((c1 == VECTOR<Aware<int> >(a2, a2 + sizeof(a2) / sizeof(a2[0]))));
		ASSERT((c2 == VECTOR<Aware<int> >(a1, a1 + sizeof(a1) / sizeof(a1[0]))));
	} ASSERT_AWARENESS
})
