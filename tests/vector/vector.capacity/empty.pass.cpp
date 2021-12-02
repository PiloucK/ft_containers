#include "myUnitTest.hpp"

TEST_CASE(Vector, Capacity, AccurateReturn, {

    {
        typedef VECTOR<Aware<int> > C;
        C c;
        ASSERT_NOEXCEPT(c.empty());
        ASSERT(c.empty());
        c.push_back(C::value_type(1));
        ASSERT(!c.empty());
        c.clear();
        ASSERT(c.empty());
    }

    ASSERT_AWARENESS
})
