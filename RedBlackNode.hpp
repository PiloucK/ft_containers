#ifndef RED_BLACK_NODE_HPP
# define RED_BLACK_NODE_HPP

template < class ValueType >
    // nullptr init to segfault on each bad dereference
    //   |-> undefined behaviour in documentation
    class RedBlackNode {

        private:
            RedBlackNode()
            {}

        public:
            typedef ValueType       value_type;
            typedef RedBlackNode *  node_pointer;

            value_type              data;
            node_pointer            parent;
            node_pointer            left;
            node_pointer            right;
            bool                    is_black;

            explicit RedBlackNode(const value_type & to_store)
                : data(to_store)
                , parent(nullptr)
                , left(nullptr)
                , right(nullptr)
                , is_black(false)
            {}

            RedBlackNode(const RedBlackNode & node)
                : data(node.data)
                , parent(node.parent)
                , left(node.left)
                , right(node.right)
                , is_black(node.is_black)
            {}

            // RedBlackNode & operator = (const RedBlackNode & rhs) {
            //     data = rhs.data;
            //     parent = rhs.parent;
            //     left = rhs.left;
            //     right = rhs.left;
            //     is_black = rhs.is_black;
            //     return (*this);
            // }

            ~RedBlackNode()
            {}

            void print(node_pointer guard) const {
                if (this == guard) {
                    std::cout << "\n                                GUARD\n\n\n";
                } else {
                    if (!is_black)
                        std::cout << "\033[1;31m";
                    std::cout << "\n                                Key: " << data.first << " | Value: " << data.second << "\033[0m\n\n\n";
                }
                if (left != nullptr) {
                    if (!left->is_black)
                        std::cout << "\033[1;31m";
                    std::cout << "\n(2)LeftKey: " << left->data.first << " | LeftValue: " << left->data.second << " \033[0m          ";
                } else {
                    std::cout << "\n           LEAF                                                      ";
                }
                if (right != nullptr) {
                    if (!right->is_black)
                        std::cout << "\033[1;31m";
                    std::cout << "(3)RightKey: " << right->data.first << " | RightValue: " << right->data.second << "\033[0m\n\n\n";
                } else {
                    std::cout << "     LEAF\n\n\n";
                }
            }

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
                return (node->parent);
            }

            node_pointer tree_node_next() {
                node_pointer node = this;
                if (node->right != nullptr) {
                    return (node->right->tree_min());
                }
                while (!(node->tree_is_left_child())) {
                    node = node->parent;
                }
                return (node->parent);
            }

            // node_pointer tree_min() const {
            //     node_pointer node;
            //     if (this->left != nullptr) {
            //         node = this->left;
            //         while (node->left != nullptr) {
            //             node = node->left;
            //         }
            //         return (node);
            //     }
            //     return (this);
            // }

            // node_pointer tree_max() const {
            //     node_pointer node;
            //     if (this->right != nullptr) {
            //         node = this->right;
            //         while (node->right != nullptr) {
            //             node = node->right;
            //         }
            //         return (node);
            //     }
            //     return (this);
            // }

            // node_pointer tree_node_prev() const {
            //     if (this->left != nullptr) {
            //         return (this->left->tree_max());
            //     }
            //     node_pointer node;
            //     if (this->tree_is_left_child()) {
            //         node = this->parent;
            //         while (node->tree_is_left_child()) {
            //             node = node->parent;
            //         }
            //         return (node->parent);
            //     }
            //     return (parent);
            // }

            // node_pointer tree_node_next() const {
            //     if (this->right != nullptr) {
            //         return (this->right->tree_min());
            //     }
            //     node_pointer node;
            //     if (!this->tree_is_left_child()) {
            //         node = this->parent;
            //         while (!(node->tree_is_left_child())) {
            //             std::cout << "toto\n";
            //             node = node->parent;
            //         }
            //         return (node->parent);
            //     }
            //     return (parent);
            // }
    };

#endif
