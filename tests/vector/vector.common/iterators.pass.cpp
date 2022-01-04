#include "myUnitTest.hpp"

struct A
{
	int first;
	int second;
};

TEST_CASE(Vector, Iterator, AccurateElementPointing, {
	{
		typedef Aware<int> T;
		typedef VECTOR<T> C;
		C c;

		C::iterator i = c.begin();
		C::iterator j = c.end();
		ASSERT(DISTANCE(i, j) == 0);
		ASSERT(i == j);
	} ASSERT_AWARENESS

	{
		typedef Aware<int> T;
		typedef VECTOR<T> C;
		const C c;

		C::const_iterator i = c.begin();
		C::const_iterator j = c.end();
		ASSERT(DISTANCE(i, j) == 0);
		ASSERT(i == j);
	} ASSERT_AWARENESS

	{
        typedef Aware<int> T;
        typedef VECTOR<T> C;
        C c;

        C::const_iterator i = c.begin();
        C::const_iterator j = c.end();
        ASSERT(DISTANCE(i, j) == 0);
        ASSERT(i == j);
        ASSERT(i == c.end());
    } ASSERT_AWARENESS

	{
		typedef Aware<int> T;
		typedef VECTOR<T> C;
		C::iterator i;
		C::const_iterator j;

		(void)i;
		(void)j;
	} ASSERT_AWARENESS
})

TEST_CASE(Vector, Iterator, ConstructFromIterator, {
	{
		typedef Aware<int> T;
		typedef VECTOR<T> C;
		T t[10];
		for (int i = 0; i < 10; i++) {
			t[i] = Aware<int>(i);
		}
		C c(t, t + (sizeof(t) / sizeof(t[0])));
		C::iterator i = c.begin();

		ASSERT(*i == 0);

		++i;
		ASSERT(*i == 1);

		*i = 10;
		ASSERT(*i == 10);
        ASSERT(DISTANCE(c.begin(), c.end()) == 10);
	} ASSERT_AWARENESS
})
