#include "myUnitTest.hpp"

TEST_CASE(Map, Capacity, MaxSize, {
	{
		typedef MAP<char COMMA int> C;
		const C::size_type max_dist = static_cast<C::size_type>(std::numeric_limits<C::difference_type>::max());
		C c;

		ASSERT(c.max_size() <= max_dist);
	}
})
