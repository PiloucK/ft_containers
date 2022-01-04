#ifndef FT_HPP
# define FT_HPP

# include <memory>

namespace ft {

    template < class T1, class T2 >
        struct pair;

    template <class Category
            , class T
            , class Distance
            , class Pointer
            , class Reference
            >
        struct iterator;

    template < class T, class Alloc >
        class Vector;
    // class Stack;
    // class Map;

    template < class InputIterator1, class InputIterator2 >
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
            while (first1 != last1) {
                if (!(*first1 == *first2)) {
                    return (false);
                }
                ++first1; ++first2;
            }
            return (true);
        }

    template < class InputIterator1, class InputIterator2, class BinaryPredicate >
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
            while (first1 != last1) {
                if (!(pred(*first1, *first2))) {
                    return (false);
                }
                ++first1; ++first2;
            }
            return (true);
        }

    template < class InputIterator1, class InputIterator2 >
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2) {
            while (first1 != last1) {
                if (first2 == last2 || *first2 < *first1) {
                    return (false);
                } else if (*first1 < *first2) {
                    return (false);
                } else {
                    ++first1; ++first2;
                }
            }
            return (first2 != last2);
        }

    template < class InputIterator1, class InputIterator2, class Compare >
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2,
                                    Compare comp) {
            while (first1 != last1) {
                if (first2 == last2 || !comp(*first2, *first1)) {
                    return (false);
                } else if (!comp(*first1, *first2)) {
                    return (false);
                } else {
                    ++first1; ++first2;
                }
            }
            return (first2 != last2);
        }

}

# include "iterator.hpp"
# include "Vector.hpp"
# include "pair.hpp"

#endif
