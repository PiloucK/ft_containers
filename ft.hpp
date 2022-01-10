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

    template < bool Cond, class T = void >
        struct enable_if {
        };

    template < class T >
        struct enable_if<true, T> {
            typedef T type;
        };

// template <class _Tp, class _Up>
// struct __has_iterator_category_convertible_to<_Tp, _Up, false> : public false_type {};
// template <class _Tp>
// struct __is_input_iterator : public __has_iterator_category_convertible_to<_Tp, input_iterator_tag> {};
// template <class _Tp>
// struct __is_forward_iterator : public __has_iterator_category_convertible_to<_Tp, forward_iterator_tag> {};
// template <class _Tp>
// struct __is_bidirectional_iterator : public __has_iterator_category_convertible_to<_Tp, bidirectional_iterator_tag> {};
// template <class _Tp>
// struct __is_random_access_iterator : public __has_iterator_category_convertible_to<_Tp, random_access_iterator_tag> {};

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
