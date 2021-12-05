#include "myUnitTest.hpp"

// template<typename T>
//     bool max_size_below_absolute_max()
//     {
//         typedef VECTOR<T> C;
//         typename C::size_type max;
//         max = static_cast<typename C::size_type>(
//                 std::numeric_limits<typename C::size_type::max() / sizeof(typename C::value_type)
//             );
        
//         C c;
//         return (c.max_size() <= max);
//     }

// TEST_CASE(Vector, Capacity, AccurateReturn, {

//     {
//         ASSERT(max_size_below_absolute_max<char>());
//         ASSERT(max_size_below_absolute_max<short>());
//         ASSERT(max_size_below_absolute_max<int>());
//         ASSERT(max_size_below_absolute_max<float>());
//         ASSERT(max_size_below_absolute_max<double>());
//         ASSERT(max_size_below_absolute_max<long>());
//         ASSERT(max_size_below_absolute_max<long long>());
//         ASSERT(max_size_below_absolute_max<Aware<int> >());
//         ASSERT(max_size_below_absolute_max<std::string>());
//         ASSERT(max_size_below_absolute_max<VECTOR<long> >());
//     } ASSERT_AWARENESS
// })
