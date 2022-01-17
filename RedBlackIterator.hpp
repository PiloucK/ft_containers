#ifndef RED_BLACK_ITERATOR_HPP
# define RED_BLACK_ITERATOR_HPP

# include "ft.hpp"
# include "RedBlackNode.hpp"

template < class ValueType >
    class RedBlackIterator : public ft::iterator<ft::bidirectional_iterator_tag, ValueType> {

        public:
            typedef ft::bidirectional_iterator_tag      iterator_category;
            typedef ValueType                           value_type;
            typedef ValueType *                         pointer;
            typedef ValueType &                         reference;
            typedef std::ptrdiff_t                      difference_type;
            typedef RedBlackNode<ValueType> *           node_pointer;

            node_pointer m_node;

        public:
            RedBlackIterator()
                : m_node()
            {}

            RedBlackIterator(const node_pointer & node)
                : m_node(node)
            {}

            RedBlackIterator(const RedBlackIterator & x)
                : m_node(x.m_node)
            {}

            ~RedBlackIterator()
            {}

            RedBlackIterator & operator = (const RedBlackIterator & rhs) {
                if (rhs != m_node) {
                    m_node = rhs.m_node;
                }
                return (*this);
            }

            reference operator * () const {
                return (m_node->data);
            }

            pointer operator -> () const {
                return (&(m_node->data));
            }

            RedBlackIterator & operator ++ () {
                m_node = m_node->tree_node_next();
                return (*this);
            }

            RedBlackIterator operator ++ (int) {
                RedBlackIterator return_iterator(*this);
                ++(*this);
                return (return_iterator);
            }

            RedBlackIterator & operator -- () {
                m_node = m_node->tree_node_prev();
                return (*this);
            }

            RedBlackIterator operator -- (int) {
                RedBlackIterator return_iterator(*this);
                --(*this);
                return (return_iterator);
            }

            friend bool operator == (const RedBlackIterator & lhs, const RedBlackIterator & rhs) {
                return (lhs.m_node == rhs.m_node);
            }

            friend bool operator != (const RedBlackIterator & lhs, const RedBlackIterator & rhs) {
                return (!(lhs == rhs));
            }

            template < class > friend class RedBlackConstIterator;

    };

template < class ValueType >
    class RedBlackConstIterator : public ft::iterator<ft::bidirectional_iterator_tag, ValueType> {

        public:
            typedef ft::bidirectional_iterator_tag      iterator_category;
            typedef const ValueType                     value_type;
            typedef const ValueType *                   pointer;
            typedef const ValueType &                   reference;
            typedef ptrdiff_t             difference_type;
            typedef RedBlackNode<ValueType> *           node_pointer;
            typedef RedBlackIterator<ValueType>         non_const_iterator;

        private:
            node_pointer m_node;

        public:
            RedBlackConstIterator()
            {}

            RedBlackConstIterator(const node_pointer & node)
                : m_node(node)
            {}

            RedBlackConstIterator(const RedBlackIterator<ValueType> & x)
                : m_node(x.m_node)
            {}

            RedBlackConstIterator(const RedBlackConstIterator<ValueType> & x)
                : m_node(x.m_node)
            {}

            ~RedBlackConstIterator()
            {}

            RedBlackConstIterator operator = (const RedBlackConstIterator & rhs) {
                m_node = rhs.m_node;
                return (*this);
            }

            reference operator * () const {
                return (m_node->data);
            }

            pointer operator -> () const {
                return (&(m_node->data));
            }

            RedBlackConstIterator & operator ++ () {
                m_node = m_node->tree_node_next();
                return (*this);
            }

            RedBlackConstIterator operator ++ (int) {
                RedBlackConstIterator return_iterator(*this);
                ++(*this);
                return (return_iterator);
            }

            RedBlackConstIterator & operator -- () {
                m_node = m_node->tree_node_prev();
                return (*this);
            }

            RedBlackConstIterator operator -- (int) {
                RedBlackConstIterator return_iterator(*this);
                --(*this);
                return (return_iterator);
            }

            friend bool operator == (const RedBlackConstIterator & lhs, const RedBlackConstIterator & rhs) {
                return (lhs.m_node == rhs.m_node);
            }

            friend bool operator != (const RedBlackConstIterator & lhs, const RedBlackConstIterator & rhs) {
                return (!(lhs == rhs));
            }

    };

#endif
