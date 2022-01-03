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

}

# include "iterator.hpp"
# include "Vector.hpp"
# include "pair.hpp"

#endif
