#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include <functional>
# include <memory>

namespace ft {

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
        class Map {

            public:
                class   iterator;
                class   value_compare;
                typedef Key                                                     key_type;
                typedef T                                                       mapped_type;
                typedef ft::pair<const key_type, mapped_type>                   value_type;
                typedef Compare                                                 key_compare;
                typedef Alloc                                                   allocator_type;
                typedef typename allocator_type::reference                      reference;
                typedef typename allocator_type::const_reference                const_reference;
                typedef typename allocator_type::pointer                        pointer;
                typedef typename allocator_type::const_pointer                  const_pointer;
                typedef ptrdiff_t                                               difference_type;
                typedef size_t                                                  size_type;
            
            private:
                class   TreeNode;
                typedef std::allocator<TreeNode>                                node_allocator_type;
                typedef TreeNode *                                              node_pointer;
            
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
                            return (m_node->value);
                        }

                        pointer operator -> () const {
                            return (allocator_type().address(m_node->value));
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
                //             return (m_node.value);
                //         }

                //         Constpointer operator -> () {
                //             return (allocator_type().address(m_node.value));
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
                allocator_type          m_allocator;
                node_allocator_type     m_node_allocator;
                node_pointer            m_root;
                node_pointer            m_begin_node;
                node_pointer            m_end_node;
                size_type               m_size;
                value_compare           value_comparator;

                // nullptr init to segfault on each bad dereference
                //   |-> undefined behaviour in documentation
                class TreeNode {

                    public:
                        pointer data;
                        node_pointer parent;
                        node_pointer left;
                        node_pointer right;
                        bool is_black;

                        TreeNode()
                            : data(nullptr)
                            , parent(nullptr)
                            , left(nullptr)
                            , right(nullptr)
                            , is_black(false)
                        {}

                        explicit TreeNode(const pointer & to_store)
                            : data(to_store)
                            , parent(nullptr)
                            , left(nullptr)
                            , right(nullptr)
                            , is_black(false)
                        {}

                        TreeNode(const TreeNode & node)
                            : data(node.data)
                            , parent(node.parent)
                            , left(node.left)
                            , right(node.right)
                            , is_black(node.is_black)
                        {}

                        TreeNode & operator = (const TreeNode & rhs) {
                            data = rhs.data;
                            parent = rhs.parent;
                            left = rhs.left;
                            right = rhs.left;
                            is_black = rhs.is_black;
                        }

                        ~TreeNode()
                        {}

                };

                bool tree_is_left_child(node_pointer x) {
                    return (x == x->parent->left);
                }

                bool tree_is_right_child(node_pointer x) {
                    return (x == x->parent->right);
                }

                /*!
                  @brief Determine if the subtree rooted at node is a proper red black subtree.
                  
                  @param node 
                  @return size_type

                  Recursively call itself and add up to the height;
                  Return 0 if is an improper subtree and the black height if proper.
                 */
                size_type tree_sub_test(node_pointer node) {
                    if (node == nullptr) {
                        return (1);
                    }
                    if (node->left != nullptr && node->left->parent != node) {
                        return (0);
                    }
                    if (node->right != nullptr && node->right->parent != node) {
                        return (0);
                    }
                    if (node->right == node->left && node->left != nullptr) {
                        return (0);
                    }
                    if (!node->is_black) {
                        if (node->left && !node->left->is_black) {
                            return (0);
                        }
                        if (node->rift && !node->right->is_black) {
                            return (0);
                        }
                    }
                    size_type black_height = tree_sub_test(node->left);
                    if (black_height == 0) {
                        return (0);
                    }
                    if (black_height != tree_sub_test(node->right)) {
                        return (0);
                    }
                    return (black_height + node->is_black);
                }

                bool tree_test(node_pointer root) {
                    if (root == nullptr) {
                        return (true);
                    }
                    if (root->parent == nullptr) {
                        return (false);
                    }
                    if (!tree_is_left_child(root)) {
                        return (false);
                    }
                    if (!root->is_black) {
                        return (false);
                    }
                    return (!!tree_sub_test(root));
                }

                node_pointer tree_min(node_pointer node) {
                    while (node->left != nullptr) {
                        node = node->left;
                    }
                    return (node);
                }

                node_pointer tree_max(node_pointer node) {
                    while (node->right != nullptr) {
                        node = node->right;
                    }
                    return (node);
                }

                node_pointer tree_node_prev(node_pointer node) {
                    if (node->next != nullptr) {
                        return (tree_max(node->right));
                    }
                    while (tree_is_left_child(node)) {
                        node = node->parent;
                    }
                    return (node);
                }

                node_pointer tree_node_next(node_pointer node) {
                    if (node->right != nullptr) {
                        return (tree_min(node->left));
                    }
                    while (tree_is_right_child(node)) {
                        node = node->parent;
                    }
                    return (node);
                }

                // node->right has to be != from nullptr
                node_pointer tree_node_rotate_left(node_pointer node) {
                    node_pointer node_right = node->right;
                    node->right = node_right->left;
                    if (node_right->left != nullptr) {
                        node_right->left->parent = node;
                    }
                    node_right->parent = node->parent;
                    if (tree_is_left_child(node)) {
                        node_right->parent->left = node_right;
                    } else {
                        node_right->parent->right = node_right;
                    }
                    node_right->left = node;
                    node->parent = node_right;
                    return (node_right);
                }

                // node->left has to be != from nullptr
                node_pointer tree_node_rotate_right(node_pointer node) {
                    node_pointer node_left = node->left;
                    node->left = node_left->right;
                    if (node_left->right != nullptr) {
                        node_left->right->parent = node;
                    }
                    node_left->parent = node->parent;
                    if (tree_is_left_child(node)) {
                        node_left->parent->left = node_left;
                    } else {
                        node_left->parent->right = node_left;
                    }
                    node_left->right = node;
                    node->parent = node_left;
                    return (node_left);
                }

                ft::pair<iterator, bool> tree_find_leaf(const key_type & k) {
                    node_pointer node_current = m_root;
                    if (node_current != nullptr) {
                        while (true) {
                            if (value_comp()(k, node_current->data)) {
                                if (node_current->left != nullptr) {
                                    node_current = node_current->left;
                                } else {
                                    return (ft::make_pair(iterator(node_current), false));
                                }
                            } else if (value_comp()(node_current->data, k)) {
                                if (node_current->right != nullptr) {
                                    node_current = node_current->right;
                                } else {
                                    return (ft::make_pair(iterator(node_current), false));
                                }
                            } else {
                                return (ft::make_pair(iterator(node_current), true));
                            }
                        }
                    }
                    return (ft::make_pair(iterator(m_end_node), false));
                }

                void destroy(node_pointer node) {
                    if (node != nullptr) {
                        destroy(node->left);
                        destroy(node->right);
                        m_allocator.destroy(node->data);
                        m_allocator.deallocate(node->data);
                        m_node_allocator.destroy(node);
                        m_node_allocator.deallocate(node);
                    }
                }
                // node_pointer detach() {
                //     node_pointer cache = m_begin_node;
                //     m_begin_node = m_end_node;
                //     m_end_node->left->parent = nullptr;
                //     m_end_node->left = nullptr;
                //     m_size = 0;
                //     if (cache->right != nullptr) {
                //         cache = static_cast<node_pointer>(cache->right);
                //     }
                // }

                // node_pointer detach(node_pointer cache) {
                //     if (cache->parent == nullptr) {
                //         return nullptr;
                //     }
                //     if ()
                //     node_pointer cache = m_begin_node;
                //     m_begin_node = m_end_node;
                //     m_end_node->left->parent = nullptr;
                //     m_end_node->left = nullptr;
                //     m_size = 0;
                //     if (cache->right != nullptr) {
                //         cache = static_cast<node_pointer>(cache->right);
                //     }
                // }

            public:
                explicit Map(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_node_allocator(node_allocator_type())
                        , m_root(nullptr)
                        , m_end_node(node_pointer())
                        , m_size(0)
                        , value_comparator(comp)
                {
                    m_begin_node = m_end_node = m_root;
                }

                // template < class InputIterator >
                //     Map(
                //         InputIterator first
                //         , InputIterator last
                //         , const key_compare & comp = key_compare()
                //         , const allocator_type & alloc = allocator_type())
                //          :
                // {}

                // Map(
                //     const Map & x)
                //         : m_node_allocator(x.m_node_allocator)
                //         , m_root(x.m_root)
                //         , m_size(x.m_size)
                //         , value_comparator(comp)
                // {
                //     m_begin_node = m_end_node = m_root;
                // }

                // Map & operator = (const Map & x) {
                //     if (this != &x) {
                //         value_comparator = x.value_comp();
                //         m_node_allocator = x.m_node_allocator;
                //         // __copy_assign_alloc(x);
                //         // __assign_multi(x.begin(), x.end());
                //     }
                //     return (*this);
                // }

                ~Map() {
                    m_node_allocator.destroy(m_root);
                }

                size_type size() const {
                    return (m_size);
                }

                size_type max_size() const {
                    return (m_node_allocator.max_size());
                }

                bool empty() const {
                    return (m_size == 0);
                }

                void clear() {
                    destroy(m_root);
                    m_size = 0;
                    m_begin_node = m_end_node;
                    m_end_node->left = nullptr;
                    m_end_node->right = nullptr;
                }

                iterator begin() {
                    return (iterator(m_begin_node));
                }

                // const_iterator begin() const {
                //     return (const_iterator(m_begin_node));
                // }

                iterator end() {
                    return (iterator(m_end_node));
                }

                // const_iterator end() const {
                //     return (const_iterator(m_end_node));
                // }

                value_compare value_comp() const {
                    return value_compare(value_comparator);
                }

                iterator find(const key_type & k) {
                    ft::pair<iterator, bool> leaf = tree_find_leaf(k);
                    if (leaf.second == true) {
                        return (leaf.first);
                    } else {
                        return (iterator(m_end_node));
                    }
                }

                size_type count(const key_type & k) const {
                    return (static_cast<size_type>(tree_find_leaf(k).second));
                }

                ft::pair<iterator, bool> insert(const value_type & val) {
                    ft::pair<iterator, bool> leaf = tree_find_leaf(val.first);
                    if (leaf.second == true)
                        return (leaf);
                    // tree_balance_after_insert(child);
                    // ++m_size;
                }

        };

}

#endif
