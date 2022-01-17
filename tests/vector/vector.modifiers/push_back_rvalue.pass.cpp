#include "myUnitTest.hpp"

TEST_CASE(Vector, PushBack, SizeChange, {
    {
        VECTOR<Aware<int> > c;

        c.push_back(Aware<int>(0));
        ASSERT(c.size() == 1);

        for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
            ASSERT(c[j] == Aware<int>(j));

        c.push_back(Aware<int>(1));
        ASSERT(c.size() == 2);

        for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
            ASSERT(c[j] == Aware<int>(j));

        c.push_back(Aware<int>(2));
        ASSERT(c.size() == 3);

        for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
            ASSERT(c[j] == Aware<int>(j));

        c.push_back(Aware<int>(3));
        ASSERT(c.size() == 4);

        for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
            ASSERT(c[j] == Aware<int>(j));

        c.push_back(Aware<int>(4));
        ASSERT(c.size() == 5);

        for (int j = 0; static_cast<std::size_t>(j) < c.size(); ++j)
            ASSERT(c[j] == Aware<int>(j));
    } ASSERT_AWARENESS
})
