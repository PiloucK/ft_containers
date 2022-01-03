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
                typedef pointer iterator;
                typedef const_pointer const_iterator;
                // reverse_iterator
                // const_reverse_iterator
                typedef ptrdiff_t difference_type;
                typedef size_t size_type;

            private:
                allocator_type m_allocator;
                pointer m_begin;
                pointer m_end;
                pointer m_end_cap;

                // allocator::allocate second parameter for possible performance improvement
                void allocate(size_type n) {
                    if (n > max_size()) {
                        throw(std::length_error("vector"));
                    }
                    m_begin = m_end = m_allocator.allocate(n, m_begin);
                    m_end_cap = m_begin + n;
                }

            protected:

            public:
                explicit Vector (
                    const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_begin(nullptr)
                        , m_end(nullptr)
                        , m_end_cap(nullptr)
                {
                    ;
                }

                explicit Vector (
                    size_type n
                    , const value_type & val = value_type()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_begin(nullptr)
                        , m_end(nullptr)
                        , m_end_cap(nullptr)
                {
                    allocate(n);
                    while (n > 0) {
                        m_allocator.construct(m_end, val);
                        ++m_end;
                        --n;
                    }
                }

                ~Vector() {
                    if (m_begin != nullptr) {
                        clear();
                        m_allocator.deallocate(m_begin, capacity());
                        m_begin = m_end = m_end_cap = nullptr;
                    }
                }

                void clear() {
                    while (m_begin != m_end) {
                        m_allocator.destroy(--m_end);
                    }
                }

                bool empty() const {
                    return (m_begin == m_end);
                }

                size_type size() const {
                    return (static_cast<size_type>(m_end - m_begin));
                }

                size_type max_size() const {
                    return (m_allocator.max_size());
                }

                size_type capacity() const {
                    return (static_cast<size_type>(m_end_cap - m_begin));
                }

                iterator begin() {
                    return (iterator(m_begin));
                }

                const_iterator begin() const {
                    return (const_iterator(m_begin));
                }

                iterator end() {
                    return (iterator(m_end));
                }

                const_iterator end() const {
                    return (const_iterator(m_end));
                }

        };

}

#endif
