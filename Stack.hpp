#ifndef STACK_HPP
# define STACK_HPP

# include "ft.hpp"

namespace ft {

    template< class T, class Container = ft::Vector<T> >
        class Stack {

            public:
                typedef Container container_type;
                typedef typename container_type::value_type value_type;
                typedef size_t size_type;

            protected:
                container_type c;

            public:
                explicit Stack (
                    const container_type & ctnr = container_type())
                        : c(ctnr)
                {
                }

                ~Stack() {
                }

                bool empty() const {
                    return (c.empty());
                }

                size_type size() const {
                    return (static_cast<size_type>(c.size()));
                }

                value_type & top() {
                    return (c.back());
                }

                const value_type & top() const {
                    return (c.back());
                }

                void push(const value_type & val) {
                    c.push_back(val);
                }

                void pop() {
                    c.pop_back();
                }

                template < class _T, class _Container >
                    friend bool operator == (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
                template < class _T, class _Container >
                    friend bool operator != (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
                template < class _T, class _Container >
                    friend bool operator < (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
                template < class _T, class _Container >
                    friend bool operator <= (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
                template < class _T, class _Container >
                    friend bool operator > (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
                template < class _T, class _Container >
                    friend bool operator >= (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs);
        };

        template < class _T, class _Container >
            bool operator == (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c == rhs.c);
            }

        template < class _T, class _Container >
            bool operator != (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c != rhs.c);
            }

        template < class _T, class _Container >
            bool operator < (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c < rhs.c);
            }

        template < class _T, class _Container >
            bool operator <= (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c <= rhs.c);
            }

        template < class _T, class _Container >
            bool operator >  (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c > rhs.c);
            }

        template < class _T, class _Container >
            bool operator >= (const Stack<_T, _Container> & lhs, const Stack<_T, _Container> & rhs) {
                return (lhs.c >= rhs.c);
            }

}

#endif
