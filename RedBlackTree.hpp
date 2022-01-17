#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "ft.hpp"
# include "RedBlackNode.hpp"
# include "RedBlackIterator.hpp"

template < class Key, class T, class Compare = std::less<Key> >
    class RedBlackTree {

        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef Compare                                         key_compare;
            typedef std::ptrdiff_t                                  difference_type;
            typedef std::size_t                                          size_type; 
            typedef RedBlackIterator<value_type>                    iterator;
            typedef RedBlackConstIterator<value_type>               const_iterator;
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

        private:
            typedef std::allocator<RedBlackNode<value_type> >       node_allocator_type;
            typedef RedBlackNode<value_type> *                      node_pointer;

            typedef node_pointer &                                  leaf_t;
            typedef ft::pair<node_pointer, bool>                    node_search_result_t;
            typedef ft::pair<leaf_t, node_search_result_t>          tree_insert_point_t;

            node_allocator_type            m_node_allocator;
            node_pointer                   m_begin_node;
            node_pointer                   m_end_node;
            size_type                      m_size;
            key_compare                    m_key_comparator;

        private:
            node_pointer construct_node(const value_type & val) {
                node_pointer new_node = m_node_allocator.allocate(1);
                m_node_allocator.construct(new_node, val);
                return (new_node);
            }

            void destroy(node_pointer & node) {
                if (node != NULL) {
                    destroy(node->left);
                    destroy(node->right);
                    m_node_allocator.destroy(node);
                    m_node_allocator.deallocate(node, 1);
                    node = NULL;
                }
            }

        public:
            // node->right has to be != from NULL
            node_pointer tree_node_rotate_left(node_pointer node) {
                node_pointer node_right = node->right;
                node->right = node_right->left;
                if (node_right->left != NULL) {
                    node_right->left->parent = node;
                }
                node_right->parent = node->parent;
                if (node->tree_is_left_child()) {
                    node_right->parent->left = node_right;
                } else {
                    node_right->parent->right = node_right;
                }
                node_right->left = node;
                node->parent = node_right;
                return (node_right);
            }

            // node->left has to be != from NULL
            node_pointer tree_node_rotate_right(node_pointer node) {
                node_pointer node_left = node->left;
                node->left = node_left->right;
                if (node_left->right != NULL) {
                    node_left->right->parent = node;
                }
                node_left->parent = node->parent;
                if (node->tree_is_left_child()) {
                    node_left->parent->left = node_left;
                } else {
                    node_left->parent->right = node_left;
                }
                node_left->right = node;
                node->parent = node_left;
                return (node_left);
            }

            void tree_balance_after_insert(node_pointer root, node_pointer new_node) {
                new_node->is_black = new_node == root;
                while (new_node != root && !new_node->parent->is_black) {
                    if (new_node->parent->tree_is_left_child()) {
                        node_pointer node_uncle = new_node->parent->parent->right;
                        if (node_uncle != NULL && !node_uncle->is_black) {
                            new_node = new_node->parent;
                            new_node->is_black = true;
                            new_node = new_node->parent;
                            new_node->is_black = (new_node == root);
                            node_uncle->is_black = true;
                        } else {
                            if (!new_node->tree_is_left_child()) {
                                new_node = new_node->parent;
                                tree_node_rotate_left(new_node);
                            }
                            new_node = new_node->parent;
                            new_node->is_black = true;
                            new_node = new_node->parent;
                            new_node->is_black = false;
                            tree_node_rotate_right(new_node);
                            break ;
                        }
                    } else {
                        node_pointer node_uncle = new_node->parent->parent->left;
                        if (node_uncle != NULL && !node_uncle->is_black) {
                            new_node = new_node->parent;
                            new_node->is_black = true;
                            new_node = new_node->parent;
                            new_node->is_black = (new_node == root);
                            node_uncle->is_black = true;
                        } else {
                            if (new_node->tree_is_left_child()) {
                                new_node = new_node->parent;
                                tree_node_rotate_right(new_node);
                            }
                            new_node = new_node->parent;
                            new_node->is_black = true;
                            new_node = new_node->parent;
                            new_node->is_black = false;
                            tree_node_rotate_left(new_node);
                            break ;
                        }
                    }
                }
            }

            void tree_node_remove(node_pointer root, node_pointer target) {
                node_pointer    initial_hole; // __y
                node_pointer    child_node; // __x
                node_pointer    child_sibling; // __w

                // Get an initial node at a bottom most of the tree of root "node_pointer root".
                // Either the target position or the very next node by value
                if (target->left == NULL || target->right == NULL) {
                    initial_hole = target;
                } else {
                    initial_hole = target->tree_node_next();
                }

                // Get a potential child of the chosen initial hole. Has to be preserved.
                if (initial_hole->left != NULL) {
                    child_node = initial_hole->left;
                } else {
                    child_node = initial_hole->right;
                }

                // Prepared to be the child's uncle and become his sibling
                child_sibling = NULL;

                // Set the child_node in place of the hole, set it's parent and find it's new sibling
                if (child_node != NULL) {
                    child_node->parent = initial_hole->parent;
                }
                if (initial_hole->tree_is_left_child()) {
                    initial_hole->parent->left = child_node;
                    if (initial_hole != root) {
                        child_sibling = initial_hole->parent->right;
                    } else {
                        root = child_node;
                    }
                } else {
                    initial_hole->parent->right = child_node;
                    child_sibling = initial_hole->parent->left;
                }

                bool    black_node_removed = initial_hole->is_black;
                if (initial_hole != target) {
                    initial_hole->parent = target->parent;
                    if (target->tree_is_left_child()) {
                        target->parent->left = initial_hole;
                    } else {
                        target->parent->right = initial_hole;
                    }
                    initial_hole->left = target->left;
                    initial_hole->left->parent = initial_hole;
                    initial_hole->right = target->right;
                    if (initial_hole->right != NULL) {
                        initial_hole->right->parent = initial_hole;
                    }
                    initial_hole->is_black = target->is_black;
                    if (root == target) {
                        root = initial_hole;
                    }
                }

                // Rebalancing
                if (black_node_removed && root != NULL) {
                    if (child_node != NULL) {
                        child_node->is_black = true;
                    } else {
                        while (true) {
                            if (!child_sibling->tree_is_left_child()) {
                                if (!child_sibling->is_black) {
                                    child_sibling->is_black = true;
                                    child_sibling->parent->is_black = false;
                                    tree_node_rotate_left(child_sibling->parent);
                                    if (root == child_sibling->left)
                                        root = child_sibling;
                                    child_sibling = child_sibling->left->right;
                                }
                                if ((child_sibling->left == NULL || child_sibling->left->is_black)
                                    && (child_sibling->right == NULL || child_sibling->right->is_black))
                                {
                                    child_sibling->is_black = false;
                                    child_node = child_sibling->parent;
                                    if (child_node == root || !child_node->is_black) {
                                        child_node->is_black = true;
                                        break ;
                                    }
                                    if (child_node->tree_is_left_child()) {
                                        child_sibling = child_node->parent->right;
                                    } else {
                                        child_sibling = child_node->parent->left;
                                    }
                                } else {
                                    if (child_sibling->right == NULL || child_sibling->right->is_black) {
                                        child_sibling->left->is_black = true;
                                        child_sibling->is_black = false;
                                        tree_node_rotate_right(child_sibling);
                                        child_sibling = child_sibling->parent;
                                    }
                                    child_sibling->is_black = child_sibling->parent->is_black;
                                    child_sibling->parent->is_black = true;
                                    child_sibling->right->is_black = true;
                                    tree_node_rotate_left(child_sibling->parent);
                                    break ;
                                }
                            } else {
                                if (!child_sibling->is_black) {
                                    child_sibling->is_black = true;
                                    child_sibling->parent->is_black = false;
                                    child_sibling->parent->tree_is_left_child();
                                    if (root == child_sibling->right) {
                                        root = child_sibling;
                                    }
                                    child_sibling = child_sibling->right->left;
                                }
                                if ((child_sibling->left == NULL || child_sibling->left->is_black)
                                    && (child_sibling->right == NULL || child_sibling->right->is_black))
                                {
                                    child_sibling->is_black = false;
                                    child_node = child_sibling->parent;
                                    if (child_node == root || !child_node->is_black) {
                                        child_node->is_black = true;
                                        break ;
                                    }
                                    if (child_node->tree_is_left_child()) {
                                        child_sibling = child_node->parent->right;
                                    } else {
                                        child_sibling = child_node->parent->left;
                                    }
                                } else {
                                    if (child_sibling->left == NULL || child_sibling->left->is_black) {
                                        child_sibling->right->is_black = true;
                                        child_sibling->is_black = false;
                                        tree_node_rotate_left(child_sibling);
                                        child_sibling = child_sibling->parent;
                                    }
                                    child_sibling->is_black = child_sibling->parent->is_black;
                                    child_sibling->parent->is_black = true;
                                    child_sibling->left->is_black = true;
                                    tree_node_rotate_right(child_sibling->parent);
                                    break ;
                                }
                            }
                        }
                    }
                }
            }

            tree_insert_point_t tree_find_insert_point(const key_type & k) const {
                node_pointer node_current = m_end_node->left;
                if (node_current != NULL) {
                    while (true) {
                        if (m_key_comparator(k, node_current->data.first)) {
                            if (node_current->left != NULL) {
                                node_current = node_current->left;
                            } else {
                                return (tree_insert_point_t(node_current->left, node_search_result_t(node_current, false)));
                            }
                        } else if (m_key_comparator(node_current->data.first, k)) {
                            if (node_current->right != NULL) {
                                node_current = node_current->right;
                            } else {
                                return (tree_insert_point_t(node_current->right, node_search_result_t(node_current, false)));
                            }
                        } else {
                            return (tree_insert_point_t(node_current, node_search_result_t(node_current, true)));
                        }
                    }
                }
                return (tree_insert_point_t(m_end_node->left, node_search_result_t(m_end_node, false)));
            }

        public:
            explicit RedBlackTree(
                const key_compare & comp = key_compare())
                    : m_node_allocator(node_allocator_type())
                    , m_end_node(construct_node(value_type(key_type(), mapped_type())))
                    , m_size(0)
                    , m_key_comparator(comp)
            {
                m_end_node->is_black = true;
                m_begin_node = m_end_node;
            }

            RedBlackTree(
                const RedBlackTree & x)
                    : m_node_allocator(x.m_node_allocator)
                    , m_end_node(construct_node(value_type(key_type(), mapped_type())))
                    , m_size(0)
                    , m_key_comparator(x.m_key_comparator)
            {
                m_end_node->is_black = true;
                m_begin_node = m_end_node;
            }

            RedBlackTree & operator = (const RedBlackTree & x) {
                if (*this != x) {
                    clear();
                    m_key_comparator = x.m_key_comparator;
                    m_node_allocator = x.m_node_allocator;
                    insert(x.begin(), x.end());
                }
                return (*this);
            }

            void destroy_at_root() {
                if (m_end_node != NULL) {
                    destroy(m_end_node->left);
                    m_end_node->left = NULL;
                }
                destroy(m_end_node);
            }

            ~RedBlackTree() {
                destroy_at_root();
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
                destroy(m_end_node->left);
                m_size = 0;
                m_begin_node = m_end_node;
                m_end_node->left = NULL;
            }

            iterator begin() {
                return (iterator(m_begin_node));
            }

            const_iterator begin() const {
                return (const_iterator(m_begin_node));
            }

            reverse_iterator rbegin() {
                return (reverse_iterator(end()));
            }

            const_reverse_iterator rbegin() const {
                return (const_reverse_iterator(end()));
            }

            iterator end() {
                return (iterator(m_end_node));
            }

            const_iterator end() const {
                return (const_iterator(m_end_node));
            }

            reverse_iterator rend() {
                return (reverse_iterator(begin()));
            }

            const_reverse_iterator rend() const {
                return (const_reverse_iterator(begin()));
            }

            iterator find(const key_type & k) {
                tree_insert_point_t insert_point = tree_find_insert_point(k);
                if (insert_point.second.second == true) {
                    return (iterator(insert_point.second.first));
                } else {
                    return (iterator(m_end_node));
                }
            }

            const_iterator find(const key_type & k) const {
                tree_insert_point_t insert_point = tree_find_insert_point(k);
                if (insert_point.second.second == true) {
                    return (const_iterator(insert_point.second.first));
                } else {
                    return (const_iterator(m_end_node));
                }
            }

            size_type count(const key_type & k) const {
                tree_insert_point_t insert_point = tree_find_insert_point(k);
                if (insert_point.second.second == true) {
                    return (1);
                } else {
                    return (0);
                }
            }

            ft::pair<iterator, bool> insert(const value_type & val) {
                tree_insert_point_t insert_point = tree_find_insert_point(val.first);
                if (insert_point.second.second == true){
                    return (ft::make_pair(iterator(insert_point.second.first), false));
                } else {
                    insert_point.first = construct_node(val);
                    insert_point.first->parent = insert_point.second.first;
                }
                if (m_end_node->left == NULL) {
                    m_end_node->left = insert_point.first;
                }
                if (m_begin_node->left != NULL) {
                    m_begin_node = m_begin_node->left;
                }
                tree_balance_after_insert(m_end_node->left, insert_point.first);
                ++m_size;
                return (ft::make_pair(iterator(insert_point.first), true));
            }

            void erase(iterator position) {
                node_pointer target = position.m_node;
                if (m_begin_node == target) {
                    m_begin_node = target->tree_node_next();
                }
                --m_size;
                tree_node_remove(m_end_node->left, target);
                m_node_allocator.destroy(target);
                m_node_allocator.deallocate(target, 1);
            }

            size_type erase(const key_type & k) {
                iterator it = find(k);
                if (it == m_end_node) {
                    return (0);
                } else {
                    erase(it);
                    return (1);
                }
            }

            void erase(iterator first, iterator last) {
                iterator target;
                while (first != last) {
                    target = first;
                    first++;
                    erase(target);
                }
            }

            ft::pair<iterator, iterator> equal_range(const key_type & k) {
                node_search_result_t search_result = tree_find_insert_point(k).second;
                if (search_result.second == true) {
                    return (ft::make_pair(iterator(search_result.first)
                            , iterator(search_result.first->tree_node_next())));
                } else {
                    if (m_key_comparator(k, search_result.first->data.first)) {
                        return (ft::make_pair(iterator(search_result.first)
                            , iterator(search_result.first)));
                    } else {
                        return (ft::make_pair(iterator(search_result.first->tree_node_next())
                            , iterator(search_result.first->tree_node_next())));
                    }
                }
            }

            ft::pair<const_iterator, const_iterator> equal_range(const key_type & k) const {
                node_search_result_t search_result = tree_find_insert_point(k).second;
                if (search_result.second == true) {
                    return (ft::make_pair(const_iterator(search_result.first)
                            , const_iterator(search_result.first->tree_node_next())));
                } else {
                    if (m_key_comparator(k, search_result.first->data.first)) {
                        return (ft::make_pair(const_iterator(search_result.first)
                            , const_iterator(search_result.first)));
                    } else {
                        return (ft::make_pair(const_iterator(search_result.first->tree_node_next())
                            , const_iterator(search_result.first->tree_node_next())));
                    }
                }
            }

            iterator lower_bound(const key_type & k) {
                return (equal_range(k).first);
            }

            const_iterator lower_bound(const key_type & k) const {
                return (equal_range(k).first);
            }

            iterator upper_bound(const key_type & k) {
                iterator bound = equal_range(k).first;
                if (bound != iterator(m_end_node)
                    && !m_key_comparator(k, bound->first)) {
                    return (++bound);
                } else {
                    return (bound);
                }
            }

            const_iterator upper_bound(const key_type & k) const {
                const_iterator bound = equal_range(k).first;
                if (bound != const_iterator(m_end_node)
                    && !m_key_comparator(k, bound->first)) {
                    return (++bound);
                } else {
                    return (bound);
                }
            }

            void swap(RedBlackTree & rhs) {
                std::swap(m_begin_node, rhs.m_begin_node);
                std::swap(m_end_node, rhs.m_end_node);
                std::swap(m_node_allocator, rhs.m_node_allocator);
                std::swap(m_size, rhs.m_size);
                std::swap(m_key_comparator, rhs.m_key_comparator);
            }

            void print() const {
                int choice;
                std::cout << "\033[2J";
                node_pointer current = m_end_node->left;
                std::cout << "Map explorer:\n";
                while (1) {
                    if (current == m_end_node) {
                        std::cout << "\n                                GUARD\n\n\n";
                    } else {
                        if (current != NULL) {
                            if (current->parent == m_end_node)
                                std::cout << "\n                                                        (1)GUARD\n\n\n";
                            else if (current->tree_is_left_child()) {
                                if (!current->parent->is_black)
                                    std::cout << "\033[1;31m";
                                std::cout << "\n                                                        (1)ParentKey: " << current->parent->data.first << " | ParentValue: " << current->parent->data.second << "\033[0m\n\n\n";
                            } else {
                                if (!current->parent->is_black)
                                    std::cout << "\033[1;31m";
                                std::cout << "\n(1)ParentKey: " << current->parent->data.first << " | ParentValue: " << current->parent->data.second << "\033[0m\n\n\n";
                            }
                            if (!current->is_black)
                                std::cout << "\033[1;31m";
                            std::cout << "\n                                Key: " << current->data.first << " | Value: " << current->data.second << "\033[0m\n\n\n";
                        } else {
                            std::cout << "\n                                                      LEAF\n\n\n";
                            return ;
                        }
                    }
                    if (current->left != NULL) {
                        if (!current->left->is_black)
                            std::cout << "\033[1;31m";
                        std::cout << "\n(2)LeftKey: " << current->left->data.first << " | LeftValue: " << current->left->data.second << "\033[0m           ";
                    } else {
                        std::cout << "\n           LEAF                                                      ";
                    }
                    if (current->right != NULL) {
                        if (!current->right->is_black)
                            std::cout << "\033[1;31m";
                        std::cout << "(3)RightKey: " << current->right->data.first << " | RightValue: " << current->right->data.second << "\033[0m\n\n\n";
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

            void print(iterator first) {
                std::cout << "\033[2J";
                std::cout << "Map explorer in order:\n";
                std::cin.get();
                std::cout << "\n\n\n--------------------------------------------------------------------\n\n\n";
                while (1) {
                    first.m_node->print(m_end_node);
                    ++first;
                    std::cout << "\n\n\n--------------------------------------------------------------------\n\n\n";
                    std::cin.get();
                }
            }

    };

#endif
