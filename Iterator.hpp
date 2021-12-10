#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <class Category              // iterator::iterator_category
        , class T                     // iterator::value_type
        , class Distance = ptrdiff_t  // iterator::difference_type
        , class Pointer = T *         // iterator::pointer
        , class Reference = T &       // iterator::reference
        >
    class Iterator
{
    ;
};

#endif
