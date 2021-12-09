// #include "myUnitTest.hpp"

// template<class C>
// 	C
// 	make(int size, int start = 0)
// 	{
// 		C c;
// 		for (int i = 0; i < size; ++i)
// 			c.push_back(start + i);

// 		return (c);
// 	}

// TEST_CASE(Vector, Access, Read, {
// 	{
// 		typedef VECTOR<Aware<int> > C;
// 		C c = make<C>(10);

// 		ASSERT_NOEXCEPT(c[0]);
// 		ASSERT_NOEXCEPT(c.at(0));
// 		ASSERT_NOEXCEPT(c.front());
// 		ASSERT_NOEXCEPT(c.back());

// 		for (int i = 0; i < 10; ++i)
// 			ASSERT(c[i] == i);

// 		for (int i = 0; i < 10; ++i)
// 			ASSERT(c.at(i) == i);

// 		ASSERT(c.front() == 0);
// 		ASSERT(c.back() == 9);
// 	} ASSERT_AWARENESS

// 	{
// 		typedef VECTOR<Aware<int> > C;
// 		const int N = 5;
// 		const C c = make<C>(10, N);

// 		ASSERT_NOEXCEPT(c[0]);
// 		ASSERT_NOEXCEPT(c.at(0));
// 		ASSERT_NOEXCEPT(c.front());
// 		ASSERT_NOEXCEPT(c.back());

// 		for (int i = 0; i < 10; ++i)
// 			ASSERT(c[i] == N + i);

// 		for (int i = 0; i < 10; ++i)
// 			ASSERT(c.at(i) == N + i);

// 		ASSERT(c.front() == N);
// 		ASSERT(c.back() == N + 9);
// 	} ASSERT_AWARENESS
// })
