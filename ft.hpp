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

    template < class T, class Container >
        class Stack;

    // class Map;

    template < class T > struct is_integral : public std::false_type {};
    template <> struct is_integral<bool> : public std::true_type {};
    template <> struct is_integral<char> : public std::true_type {};
    template <> struct is_integral<char16_t> : public std::true_type {};
    template <> struct is_integral<char32_t> : public std::true_type {};
    template <> struct is_integral<wchar_t> : public std::true_type {};
    template <> struct is_integral<signed char> : public std::true_type {};
    template <> struct is_integral<short int> : public std::true_type {};
    template <> struct is_integral<int> : public std::true_type {};
    template <> struct is_integral<long int> : public std::true_type {};
    template <> struct is_integral<long long int> : public std::true_type {};
    template <> struct is_integral<unsigned char> : public std::true_type {};
    template <> struct is_integral<unsigned short int> : public std::true_type {};
    template <> struct is_integral<unsigned int> : public std::true_type {};
    template <> struct is_integral<unsigned long int> : public std::true_type {};
    template <> struct is_integral<unsigned long long int> : public std::true_type {};

    template < bool Cond, class T = void >
        struct enable_if {
        };

    template < class T >
        struct enable_if<true, T> {
            typedef T type;
        };

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
            for (; first2 != last2; ++first1, ++first2) {
                if (first1 == last1 || *first2 < *first1) {
                    return (false);
                } else if (*first1 < *first2) {
                    return (true);
                }
            }
            return (first2 != last2);
        }

    template < class InputIterator1, class InputIterator2, class Compare >
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2,
                                    Compare comp) {
            for (; first1 != last1; ++first1, ++first2) {
                if (first2 == last2 || !comp(*first2, *first1)) {
                    return (false);
                } else if (!comp(*first1, *first2)) {
                    return (true);
                }
            }
            return (first2 != last2);
        }

}

# include "iterator.hpp"
# include "Vector.hpp"
# include "pair.hpp"

#endif
