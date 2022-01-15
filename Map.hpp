#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include <functional>
# include <memory>

# define CLEAR_STDOUT std::cout << "\033[2J";
# define WAIT_INPUT std::cin.get();
# define START_INFO std::cout << "To start the tests or go to the next one, press ENTER\n";
# define NEXT_TEST std::cin.get(); std::cout << "\033[2J"; std::cout << "To start the tests or go to the next one, press ENTER\n\n\n";

namespace ft {

    template < class ValueType, class NodePointer, class DiffType >
        class RedBlackIterator {

            private:
                typedef NodePointer                         node_pointer;

                node_pointer m_node;

            public:
                typedef ft::bidirectional_iterator_tag      iterator_category;
                typedef ValueType                           value_type;
                typedef DiffType                            difference_type;
                typedef ValueType *                         pointer;
                typedef ValueType &                         reference;

                RedBlackIterator()
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
                    m_node = rhs.m_node;
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
                // friend bool operator == (const iterator & lhs, const iterator & rhs);
                // friend bool operator != (const iterator & lhs, const iterator & rhs);

        };

        // bool operator == (const RedBlackIterator & lhs, const RedBlackIterator & rhs) {
        //     return (*(lhs.m_node) == *(rhs.m_node));
        // }

        // template < class Key_, class T_ >
        //     bool operator != (const typename Map<Key_, T_>::iterator & lhs, const typename Map<Key_, T_>::iterator & rhs) {
        //         return (!(lhs == rhs));
        //     }

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
        //             m_node = tree_node_prev(m_node);
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

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
        class RedBlackTree {

            private:
                class   TreeNode;
                typedef std::allocator<TreeNode>                                        node_allocator_type;
                typedef TreeNode *                                                      node_pointer;

            public:
                class   value_compare;

                typedef Key                                                             key_type;
                typedef T                                                               mapped_type;
                typedef ft::pair<const key_type, mapped_type>                           value_type;
                typedef Compare                                                         key_compare;
                typedef Alloc                                                           allocator_type;
                typedef typename allocator_type::reference                              reference;
                typedef typename allocator_type::const_reference                        const_reference;
                typedef typename allocator_type::pointer                                pointer;
                typedef typename allocator_type::const_pointer                          const_pointer;
                typedef ptrdiff_t                                                       difference_type;
                typedef size_t                                                          size_type;
                typedef RedBlackIterator<value_type, node_pointer, difference_type>     iterator;
            
            private:
                allocator_type          m_allocator;
                node_allocator_type     m_node_allocator;
                node_pointer            m_root;
                node_pointer            m_begin_node;
                TreeNode                m_end_node;
                size_type               m_size;
                value_compare           m_value_comparator;

            public:
                class value_compare
                    : public std::binary_function<value_type, value_type, bool> {

                    friend class RedBlackTree;

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

                value_compare value_comp() const {
                    return value_compare(m_value_comparator);
                }

            private:
                // nullptr init to segfault on each bad dereference
                //   |-> undefined behaviour in documentation
                class TreeNode {

                    public:
                        value_type      data;
                        node_pointer    parent;
                        node_pointer    left;
                        node_pointer    right;
                        bool            is_black;

                        TreeNode()
                            : data(key_type(), mapped_type())
                            , parent(nullptr)
                            , left(nullptr)
                            , right(nullptr)
                            , is_black(false)
                        {}

                        explicit TreeNode(const value_type & to_store)
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

                        // TreeNode & operator = (const TreeNode & rhs) {
                        //     data = rhs.data;
                        //     parent = rhs.parent;
                        //     left = rhs.left;
                        //     right = rhs.left;
                        //     is_black = rhs.is_black;
                        //     return (*this);
                        // }

                        ~TreeNode()
                        {}

                        bool tree_is_left_child() {
                            return (this == parent->left);
                        }

                        node_pointer tree_min() {
                            node_pointer node = this;
                            while (node->left != nullptr) {
                                node = left;
                            }
                            return (node);
                        }

                        node_pointer tree_max() {
                            node_pointer node = this;
                            while (node->right != nullptr) {
                                node = node->right;
                            }
                            return (node);
                        }

                        node_pointer tree_node_prev() {
                            node_pointer node = this;
                            if (node->left != nullptr) {
                                return (node->left->tree_max());
                            }
                            while (node->tree_is_left_child()) {
                                node = node->parent;
                            }
                            return (node);
                        }

                        node_pointer tree_node_next() {
                            node_pointer node = this;
                            if (node->right != nullptr) {
                                return (node->right->tree_min());
                            }
                            while (!(node->tree_is_left_child())) {
                                node = node->parent;
                            }
                            return (node);
                        }

                };

            public:
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

                typedef node_pointer &                              leaf_t;
                typedef ft::pair<node_pointer, bool>                node_search_result_t;
                typedef ft::pair<leaf_t, node_search_result_t>      tree_insert_point_t;

                tree_insert_point_t tree_find_insert_point(const key_type & k) {
                    node_pointer node_current = m_root;
                    value_type pseudo_value(k, mapped_type());
                    if (node_current != nullptr) {
                        while (true) {
                            if (value_comp()(pseudo_value, node_current->data)) {
                                if (node_current->left != nullptr) {
                                    node_current = node_current->left;
                                } else {
                                    return (tree_insert_point_t(node_current->left, node_search_result_t(node_current, false)));
                                }
                            } else if (value_comp()(node_current->data, pseudo_value)) {
                                if (node_current->right != nullptr) {
                                    node_current = node_current->right;
                                } else {
                                    return (tree_insert_point_t(node_current->right, node_search_result_t(node_current, false)));
                                }
                            } else {
                                return (tree_insert_point_t(node_current, node_search_result_t(node_current, true)));
                            }
                        }
                    }
                    return (tree_insert_point_t(m_end_node.left, node_search_result_t(&m_end_node, false)));
                }

                void destroy(node_pointer & node) {
                    if (node != nullptr) {
                        destroy(node->left);
                        destroy(node->right);
                        m_node_allocator.destroy(node);
                        m_node_allocator.deallocate(node, 1);
                        node = nullptr;
                    }
                }

                void destroy_at_root() {
                    destroy(m_root);
                }

                node_pointer construct_node(const value_type & val) {
                    node_pointer new_node = m_node_allocator.allocate(1);
                    m_node_allocator.construct(new_node, val);
                    return (new_node);
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
                explicit RedBlackTree(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_node_allocator(node_allocator_type())
                        , m_root(nullptr)
                        , m_end_node(TreeNode())
                        , m_size(0)
                        , m_value_comparator(comp)
                {
                    m_end_node.parent = &m_end_node;
                    m_begin_node = &m_end_node;
                }

                // template < class InputIterator >
                //     RedBlackTree(
                //         InputIterator first
                //         , InputIterator last
                //         , const key_compare & comp = key_compare()
                //         , const allocator_type & alloc = allocator_type())
                //          :
                // {}

                // RedBlackTree(
                //     const RedBlackTree & x)
                //         : m_node_allocator(x.m_node_allocator)
                //         , m_root(x.m_root)
                //         , m_size(x.m_size)
                //         , m_value_comparator(comp)
                // {
                //     m_begin_node = m_end_node = m_root;
                // }

                // RedBlackTree & operator = (const RedBlackTree & x) {
                //     if (this != &x) {
                //         m_value_comparator = x.value_comp();
                //         m_node_allocator = x.m_node_allocator;
                //         // __copy_assign_alloc(x);
                //         // __assign_multi(x.begin(), x.end());
                //     }
                //     return (*this);
                // }

                ~RedBlackTree() {
                    // destroy(m_root);
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
                    if (m_root != nullptr)
                        std::cout << "nonull \n";
                    m_size = 0;
                    m_begin_node = &m_end_node;
                    m_end_node.left = nullptr;
                    m_end_node.right = nullptr;
                }

                iterator begin() {
                    return (iterator(m_begin_node));
                }

                // const_iterator begin() const {
                //     return (const_iterator(m_begin_node));
                // }

                iterator end() {
                    return (iterator(&m_end_node));
                }

                // const_iterator end() const {
                //     return (const_iterator(&m_end_node));
                // }

                iterator find(const key_type & k) {
                    ft::pair<node_pointer &, ft::pair<node_pointer, bool> > insert_point = tree_find_insert_point(k);
                    if (insert_point.second.second == true) {
                        return (iterator(insert_point.second.first));
                    } else {
                        return (iterator(&m_end_node));
                    }
                }

                size_type count(const key_type & k) const {
                    return (static_cast<size_type>(tree_find_insert_point(k).second));
                }

                ft::pair<iterator, bool> insert(const value_type & val) {
                    ft::pair<node_pointer &, ft::pair<node_pointer, bool> > insert_point = tree_find_insert_point(val.first);
                    if (insert_point.second.second == true){
                        return (ft::make_pair(iterator(insert_point.second.first), false));
                    } else {
                        insert_point.first = construct_node(val);
                        insert_point.first->parent = insert_point.second.first;
                    }
                    if (m_root == nullptr) {
                        m_root = insert_point.first;
                    }
                    if (m_begin_node->left != nullptr) {
                        m_begin_node = m_begin_node->left;
                    }
                    // tree_balance_after_insert(child);
                    ++m_size;
                    return (ft::make_pair(iterator(insert_point.first), true));
                }

                void print() const {
                    int choice;
                    std::cout << "\033[2J";
                    node_pointer current = m_root;
                    std::cout << "Map explorer:\n";
                    std::cin.get();
                    while (1) {
                        if (current == &m_end_node) {
                            std::cout << "\n                                GUARD\n\n\n";
                        } else {
                            if (current != nullptr) {
                                if (current->parent == &m_end_node)
                                    std::cout << "\n                                                           GUARD\n\n\n";
                                else if (current->tree_is_left_child()) {
                                    std::cout << "\n                                                        (1)ParentKey: " << current->parent->data.first << " | ParentValue: " << current->parent->data.second << "\n\n\n";
                                } else {
                                    std::cout << "\n(1)ParentKey: " << current->parent->data.first << " | ParentValue: " << current->parent->data.second << "\n\n\n";
                                }
                                std::cout << "\n                                Key: " << current->data.first << " | Value: " << current->data.second << "\n\n\n";
                            } else {
                                std::cout << "\n                                                      LEAF\n\n\n";
                                return ;
                            }
                        }
                        if (current->left != nullptr) {
                            std::cout << "\n(2)LeftKey: " << current->left->data.first << " | LeftValue: " << current->left->data.second << "           ";
                        } else {
                            std::cout << "\n           LEAF                                                      ";
                        }
                        if (current->right != nullptr) {
                            std::cout << "(3)RightKey: " << current->right->data.first << " | RightValue: " << current->right->data.second << "\n\n\n";
                        } else {
                            std::cout << "     LEAF\n\n\n";
                        }
                        std::cin >> choice;
                        if (choice == 1)
                            current = current->parent;
                        if (choice == 2)
                            current = current->left;
                        if (choice == 3)
                            current = current->right;
                        std::cout << "\n\n\n--------------------------------------------------------------------\n\n\n";
                        std::cin.get();
                    }
                }

        };

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
        class Map {
            private:
                typedef RedBlackTree<Key, T, Compare, Alloc>            tree_type;

            public:
                typedef typename tree_type::key_type                    key_type;
                typedef typename tree_type::mapped_type                 mapped_type;
                typedef typename tree_type::value_type                  value_type;
                typedef typename tree_type::key_compare                 key_compare;
                typedef typename tree_type::allocator_type              allocator_type;
                typedef typename tree_type::reference                   reference;
                typedef typename tree_type::const_reference             const_reference;
                typedef typename tree_type::pointer                     pointer;
                typedef typename tree_type::const_pointer               const_pointer;
                typedef typename tree_type::difference_type             difference_type;
                typedef typename tree_type::size_type                   size_type;
                typedef typename tree_type::iterator                    iterator;

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

                value_compare value_comp() const {
                    return value_compare(m_value_comparator);
                }

            private:
                allocator_type      m_allocator;
                value_compare       m_value_comparator;
                tree_type           m_tree;

            public:
                void print() const { // TO PRIVATE
                    m_tree.print();
                }

            public:
                explicit Map(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_value_comparator(comp)
                        , m_tree()
                {}

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
                //         , m_value_comparator(comp)
                // {
                //     m_begin_node = m_end_node = m_root;
                // }

                // Map & operator = (const Map & x) {
                //     if (this != &x) {
                //         m_value_comparator = x.value_comp();
                //         m_node_allocator = x.m_node_allocator;
                //         // __copy_assign_alloc(x);
                //         // __assign_multi(x.begin(), x.end());
                //     }
                //     return (*this);
                // }

                ~Map()
                {
                    m_tree.destroy_at_root();
                }

                size_type size() const {
                    return (m_tree.size());
                }

                size_type max_size() const {
                    return (m_tree.max_size());
                }

                bool empty() const {
                    return (m_tree.empty());
                }

                void clear() {
                    m_tree.clear();
                }

                iterator begin() {
                    return (m_tree.begin());
                }

                // const_iterator begin() const {
                //     return (const_iterator(m_begin_node));
                // }

                iterator end() {
                    return (m_tree.end());
                }

                // const_iterator end() const {
                //     return (const_iterator(&m_end_node));
                // }

                iterator find(const key_type & k) {
                    return (m_tree.find(k));
                }

                size_type count(const key_type & k) const {
                    return (m_tree.count(k));
                }

                ft::pair<iterator, bool> insert(const value_type & val) {
                    return (m_tree.insert(val));
                }

        };

}

#endif
