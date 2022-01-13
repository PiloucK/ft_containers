#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include <functional>
# include <memory>

namespace ft {

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
        class Map {

            public:
                typedef Key key_type;
                typedef T mapped_type;
                typedef ft::pair<const key_type, mapped_type> value_type;
                typedef Compare key_compare;
                typedef Alloc allocator_type;
                typedef typename allocator_type::reference reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer pointer;
                typedef typename allocator_type::const_pointer const_pointer;
                // typedef ft::iterator_traits<iterator>::difference_type difference_type;
                typedef size_t size_type;

            public:
                class value_compare
                    : public std::binary_function<value_type, value_type, bool> {

                    friend class Map;

                    protected:
                        Compare comp;

                        value_compare(key_compare c)
                            : comp(c)
                        {}

                    public:
                        bool operator() (const value_type & x, const value_type & y) const {
                            return comp(x.first, y.first);
                        }

                };

            private:
                class TreeEndNode {

                    public:
                        pointer m_left;

                        TreeEndNode()
                            : m_left()
                        {}

                };

                class TreeNodeBase : public TreeEndNode {

                    public:
                        // typedef TreeEndNode base;

                        pointer m_parent;
                        pointer m_right;
                        bool m_is_black;

                        TreeNodeBase()
                            : m_parent()
                            , m_right()
                            , m_is_black(false)
                        {
                        }

                };

                class TreeNode : public TreeNodeBase {

                    public:
                        value_type m_value;

                        explicit TreeNode(const value_type & val)
                            : m_value(val)
                        {}

                        TreeNode(const TreeNode & node)
                            : m_value(node.m_value)
                        {}

                };

                typedef std::allocator<TreeNode> node_allocator_type;
                typedef TreeNode * node_pointer;

            public:
                class iterator
                    : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {

                    private:
                        node_pointer m_node;

                    public:
                        iterator()
                        {}

                        iterator(const node_pointer & node)
                            : m_node(node)
                        {}

                        iterator(const iterator & x)
                            : m_node(x.m_node)
                        {}

                        ~iterator()
                        {}

                        reference operator * () const {
                            return (m_node->m_value);
                        }

                        pointer operator -> () const {
                            return (allocator_type().address(m_node->m_value));
                        }

                        iterator & operator ++ () {
                            m_node = tree_next(m_node);
                            return (*this);
                        }

                        iterator operator ++ (int) {
                            iterator return_iterator(*this);
                            ++(*this);
                            return (return_iterator);
                        }

                        iterator & operator -- () {
                            m_node = tree_prev(m_node);
                            return (*this);
                        }

                        iterator operator -- (int) {
                            iterator return_iterator(*this);
                            --(*this);
                            return (return_iterator);
                        }

                        // bool operator == (const iterator & lhs, const iterator & rhs) {
                        //     return (lhs.m_node == rhs.m_node);
                        // }

                        // bool operator != (const iterator & lhs, const iterator & rhs) {
                        //     return (!(lhs == rhs));
                        // }

                };

                // class const_iterator
                //     : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {

                //     private:
                //         const TreeNode m_node;

                //     public:
                //         const_iterator()
                //         {}

                //         const_iterator(const value_type & val)
                //             : m_node(TreeNode(val))
                //         {}

                //         const_iterator(iterator it)
                //             : m_node(*it))
                //         {}

                //         ~const_iterator()
                //         {}

                //         reference operator * () {
                //             return (m_node.m_value);
                //         }

                //         Constpointer operator -> () {
                //             return (allocator_type().address(m_node.m_value));
                //         }

                //         const_iterator & operator ++ () {
                //             m_node = tree_next(m_node);
                //             return (*this);
                //         }

                //         const_iterator operator ++ (int) {
                //             const_iterator return_iterator(*this);
                //             ++(*this);
                //             return (return_iterator);
                //         }

                //         const_iterator & operator -- () {
                //             m_node = tree_prev(m_node);
                //             return (*this);
                //         }

                //         const_iterator operator -- (int) {
                //             iterator return_iterator(*this);
                //             --(*this);
                //             return (return_iterator);
                //         }

                //         bool operator == (const const_iterator & lhs, const const_iterator & rhs) {
                //             return (lhs.m_node == rhs.m_node);
                //         }

                //         bool operator != (const const_iterator & lhs, const const_iterator & rhs) {
                //             return (!(lhs == rhs));
                //         }

                // };

            private:
                allocator_type m_value_allocator;
                node_allocator_type m_node_allocator; // pair1.second
                node_pointer m_begin_node;
                node_pointer m_end_node; // pair1.first
                size_type m_size; // pair3.first
                value_compare m_value_comparator; // pair3.second

            public:

                explicit Map(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_value_allocator(alloc)
                        , m_node_allocator(node_allocator_type())
                        , m_begin_node(node_pointer())
                        , m_end_node(node_pointer())
                        , m_size(0)
                        , m_value_comparator(comp)
                {}

                // template < class InputIterator >
                //     Map(
                //         InputIterator first
                //         , InputIterator last
                //         , const key_compare & comp = key_compare()
                //         , const allocator_type & alloc = allocator_type())
                //          :
                // {}

                // Map(const Map & x)
                //     :
                // {}

                size_type size() const {
                    return (m_size);
                }

                // size_type max_size() const {
                //     return (m_node_allocator.max_size());
                // }

                bool empty() const {
                    return (m_size == 0);
                }

                iterator begin() {
                    return (iterator(m_begin_node));
                }

                // const_iterator begin() const {
                //     return (iterator(m_begin_node));
                // }

                iterator end() {
                    return (iterator(m_end_node));
                }

                // const iterator end() const {
                //     return (iterator(m_end_node));
                // }

                value_compare value_comp() const {
                    return value_compare(m_value_comparator);
                }

        };

}

#endif
