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
                typedef ft::reverse_iterator<iterator> reverse_iterator;
                typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
                        throw(std::length_error("Vector"));
                    }
                    m_begin = m_end = m_allocator.allocate(n, m_begin);
                    m_end_cap = m_begin + n;
                }

                void deallocate() {
                    m_allocator.deallocate(m_begin, capacity());
                    m_begin = m_end = m_end_cap = nullptr;
                }

                void construct_at_end(size_type n, const_reference val) {
                    while (n > 0) {
                        m_allocator.construct(m_end, val);
                        ++m_end;
                        --n;
                    }
                }

                template < class InputIterator >
                    void construct_at_end(InputIterator first, InputIterator last) {
                        for (; first != last; ++first) {
                            m_allocator.construct(m_end, *first);
                            ++m_end;
                        }
                    }
                
                void destruct_at_end(pointer new_last) {
                    while (m_end != new_last) {
                        m_allocator.destroy(--m_end);
                    }
                }

                size_type recommend(size_type new_size) const {
                    const size_type ms = max_size();
                    if (new_size > ms) {
                        throw (std::length_error("Vector"));
                    }
                    const size_type cap = capacity();
                    if (cap >= ms / 2) {
                        return (ms);
                    } else {
                        return (std::max<size_type>(2 * cap, new_size));
                    }
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
                    if (n > 0) {
                        allocate(n);
                        construct_at_end(n, val);
                    }
                }

                template < class InputIterator >
                    Vector(
                        InputIterator first
                        , typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last
                        , const allocator_type & alloc = allocator_type())
                            : m_allocator(alloc)
                            , m_begin(nullptr)
                            , m_end(nullptr)
                            , m_end_cap(nullptr)
                    {
                        size_type n = static_cast<size_type>(distance(first, last));
                        if (n > 0) {
                            allocate(n);
                            construct_at_end(first, last);
                        }
                    }

                Vector(
                    const Vector & x)
                        : m_allocator(x.m_allocator)
                        , m_begin(nullptr)
                        , m_end(nullptr)
                        , m_end_cap(nullptr)
                {
                    size_type n = static_cast<size_type>(x.capacity());
                    if (n > 0) {
                        allocate(n);
                        construct_at_end(x.m_begin, x.m_end);
                    }
                }

                Vector & operator = (const Vector & x) {
                    if (this != &x) {
                        assign(x.m_begin, x.m_end);
                    }
                    return (*this);
                }

                ~Vector() {
                    if (m_begin != nullptr) {
                        clear();
                        deallocate();
                    }
                }

                bool empty() const {
                    return (m_begin == m_end);
                }

                void clear() {
                    while (m_begin != m_end) {
                        m_allocator.destroy(--m_end);
                    }
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

                reverse_iterator rbegin() {
                    return (reverse_iterator(end()));
                }

                const_reverse_iterator rbegin() const {
                    return (const_reverse_iterator(end()));
                }

                reverse_iterator rend() {
                    return (reverse_iterator(begin()));
                }

                const_reverse_iterator rend() const {
                    return (const_reverse_iterator(begin()));
                }

                reference front() {
                    return (*m_begin);
                }

                const_reference front() const {
                    return (*m_begin);
                }

                reference back() {
                    return (*(m_end - 1));
                }

                const_reference back() const {
                    return (*(m_end - 1));
                }

                allocator_type get_allocator() const {
                    return (m_allocator);
                }

                reference operator [] (size_type n) {
                    return (m_begin[n]);
                }

                const_reference operator [] (size_type n) const {
                    return (m_begin[n]);
                }

                reference at (size_type n) {
                    if (n >= size()) {
                        throw (std::out_of_range("Vector"));
                    }
                    return (m_begin[n]);
                }

                const_reference at (size_type n) const {
                    if (n >= size()) {
                        throw (std::out_of_range("Vector"));
                    }
                    return (m_begin[n]);
                }

                void reserve(size_type n) {
                    if (n > capacity()) {
                        Vector _v(m_allocator);
                        _v.allocate(n);
                        _v.construct_at_end(m_begin, m_end);
                        swap(_v);
                    }
                }

                template < class InputIterator>
                    void assign(InputIterator first, InputIterator last) {
                        clear();
                        size_type new_size = static_cast<size_type>(distance(first, last));
                        if (new_size <= capacity()) {
                            construct_at_end(first, last);
                        } else {
                            deallocate();
                            allocate(recommend(new_size));
                            construct_at_end(first, last);
                        }
                    }

                void assign (size_type n, const value_type & val) {
                    clear();
                    if (n <= capacity()) {
                        construct_at_end(n, val);
                    } else {
                        deallocate();
                        allocate(recommend(n));
                        construct_at_end(n, val);
                    }
                }

                void push_back(const value_type & val) {
                    if (m_end == m_end_cap) {
                        reserve(recommend(capacity() + 1));
                    }
                    m_allocator.construct(m_end, val);
                    ++m_end;
                }

                void pop_back() {
                    destruct_at_end(m_end - 1);
                }

                iterator erase(iterator position) {
                    iterator it_return(position);
                    if (position != m_end) {
                        for (; position < m_end - 1; position++) {
                            *position = *(position + 1);
                        }
                    }
                    destruct_at_end(m_end - 1);
                    return (it_return);
                }

                iterator erase(iterator first, iterator last) {
                    iterator it_return(first);
                    difference_type n = last - first;
                    if (size() != static_cast<size_type>(n)) {
                        while (first != m_end - n) {
                            *first = *(first + n);
                            ++first;
                        }
                    }
                    destruct_at_end(m_end - n);
                    return (it_return);
                }

                iterator insert(iterator position, const value_type & val) {
                    if (m_end < m_end_cap) {
                        if (position == m_end) {
                            push_back(val);
                        } else {
                            Vector _v(position, m_end);
                            destruct_at_end(position);
                            push_back(val);
                            construct_at_end(_v.m_begin, _v.m_end);
                        }
                    } else {
                        Vector _v;
                        _v.allocate(recommend(size() + 1));
                        _v.construct_at_end(m_begin, position);
                        iterator new_position(_v.m_end);
                        _v.push_back(val);
                        _v.construct_at_end(position, m_end);
                        position = new_position;
                        swap(_v);
                    }
                    return (position);
                }

                void insert(iterator position, size_type n, const value_type & val) {
                    if (n > 0) {
                        if (n <= static_cast<size_type>(m_end_cap - m_end)) {
                            if (position == m_end) {
                                construct_at_end(n, val);
                            } else {
                                Vector _v(position, m_end);
                                destruct_at_end(position);
                                construct_at_end(n, val);
                                construct_at_end(_v.m_begin, _v.m_end);
                            }
                        } else {
                            Vector _v;
                            _v.allocate(recommend(size() + n));
                            _v.construct_at_end(m_begin, position);
                            _v.construct_at_end(n, val);
                            _v.construct_at_end(position, m_end);
                            swap(_v);
                        }
                    }
                }

                template < class InputIterator >
                    void insert(iterator position, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
                        difference_type n = ft::distance(first, last);
                        if (n > 0) {
                            if (n <= static_cast<size_type>(m_end_cap - m_end)) {
                                if (position == m_end) {
                                    construct_at_end(first, last);
                                } else {
                                    Vector _v(position, m_end);
                                    destruct_at_end(position);
                                    construct_at_end(first, last);
                                    construct_at_end(_v.m_begin, _v.m_end);
                                }
                            } else {
                                Vector _v;
                                _v.allocate(recommend(size() + n));
                                _v.construct_at_end(m_begin, position);
                                _v.construct_at_end(first, last);
                                _v.construct_at_end(position, m_end);
                                swap(_v);
                            }
                        }
                    }

                void swap(Vector & x) {
                    std::swap(m_begin, x.m_begin);
                    std::swap(m_end, x.m_end);
                    std::swap(m_end_cap, x.m_end_cap);
                    std::swap(m_allocator, x.m_allocator);
                }

                void resize(size_type n, value_type val = value_type()) {
                    size_type current_size = size();
                    if (n < current_size) {
                        destruct_at_end(m_end - n);
                    } else if (n > current_size) {
                        if (n <= capacity()) {
                            construct_at_end(n - current_size, val);
                        } else {
                            reserve(recommend(n));
                            construct_at_end(n - current_size, val);
                        }
                    }
                }

        };

        template < class T, class Alloc >
            bool operator == (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                const typename Vector<T, Alloc>::size_type lhs_size = lhs.size();
                return (lhs_size == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
            }

        template < class T, class Alloc >
            bool operator != (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                return (!(lhs == rhs));
            }

        template < class T, class Alloc >
            bool operator <  (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
            }

        template < class T, class Alloc >
            bool operator <= (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                return (!(rhs < lhs));
            }

        template < class T, class Alloc >
            bool operator >  (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                return (!(lhs < rhs));
            }

        template < class T, class Alloc >
            bool operator >= (const Vector<T,Alloc> & lhs, const Vector<T,Alloc> & rhs) {
                return (!(lhs < rhs));
            }

}

#endif
