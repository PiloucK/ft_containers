#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft.hpp"
# include <cstdlib>
# include <memory>

namespace ft {

    template< class T, class Alloc = std::allocator<T> >
        class Vector {

            public:
                typedef T value_type;
                typedef Alloc allocator_type;
                typedef typename allocator_type::reference reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer pointer;
                typedef typename allocator_type::const_pointer const_pointer;
                // iterator
                // const_iterator
                // reverse_iterator
                // const_reverse_iterator
                // difference_type
                typedef size_t size_type;

                explicit Vector(const allocator_type & alloc = allocator_type()) : m_allocator(alloc), m_size(0), m_capacity(0) {
                    ;
                }

                // Vector() : m_size(0) {
                //     ;
                // }

                ~Vector() {
                    ;
                }

                bool empty() const {
                    if (m_size != 0) {
                        return (false);
                    } else {
                        return (true);
                    }
                }

                size_type size() const {
                    return (m_size);
                }
                // size_type size() const {
                //     ;
                // };

            protected:

            private:
                allocator_type m_allocator;
                value_type * m_array;
                size_type m_size;
                size_type m_capacity;

        };

}

#endif
