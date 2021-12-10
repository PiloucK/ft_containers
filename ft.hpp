#ifndef FT_HPP
# define FT_HPP

# include <memory>

namespace ft {

    template <class Category
            , class T
            , class Distance
            , class Pointer
            , class Reference
            >
        class Iterator;

    template < class T, class Alloc>
        class Vector;
    // class Stack;
    // class Map;

}

# include "Iterator.hpp"
# include "Vector.hpp"

#endif
