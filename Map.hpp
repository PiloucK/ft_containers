#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include <functional>
# include <memory>

namespace ft {

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
        class Map {

            public:
                // typedef Key key_type
                // typedef T mapped_type;
                // typedef ft::pair<const key_type, mapped_type> value_type;
                // typedef Compare key_compare;
                // typedef Alloc allocator_type;
                // typedef typename allocator_type::reference reference;
                // typedef typename allocator_type::const_reference const_reference;
                // typedef typename allocator_type::pointer pointer;
                // typedef typename allocator_type::const_pointer const_pointer;
                // // typedef pointer iterator;
                // // typedef const_pointer const_iterator;
                // // typedef ft::reverse_iterator<iterator> reverse_iterator;
                // // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
                // // typedef ft::iterator_traits<iterator>::difference_type difference_type;
                // typedef allocator_type::size_type size_type;

            private:
        };

}

#endif
