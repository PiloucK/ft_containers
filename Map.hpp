#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include "RedBlackTree.hpp"
# include <functional>
# include <memory>

namespace ft {

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
                typedef typename tree_type::const_iterator              const_iterator;
                typedef typename tree_type::reverse_iterator            reverse_iterator;
                typedef typename tree_type::const_reverse_iterator      const_reverse_iterator;

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

            public: // TO PRIVATE
                void print() const {
                    m_tree.print();
                }

                void print(iterator first) {
                    m_tree.print(first);
                }

            public:
                explicit Map(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_value_comparator(comp)
                        , m_tree(comp, alloc)
                {}

                template < class InputIterator >
                    Map(
                        InputIterator first
                        , InputIterator last
                        , const key_compare & comp = key_compare()
                        , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_value_comparator(comp)
                        , m_tree(comp, alloc)
                {
                    insert(first, last);
                }

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

                const_iterator begin() const {
                    return (m_tree.begin());
                }

                reverse_iterator rbegin() {
                    return (m_tree.rbegin());
                }

                const_reverse_iterator rbegin() const {
                    return (m_tree.rbegin());
                }

                iterator end() {
                    return (m_tree.end());
                }

                const_iterator end() const {
                    return (m_tree.end());
                }

                reverse_iterator rend() {
                    return (m_tree.rend());
                }

                const_reverse_iterator rend() const {
                    return (m_tree.rend());
                }

                iterator find(const key_type & k) {
                    return (m_tree.find(k));
                }

                size_type count(const key_type & k) const {
                    return (m_tree.count(k));
                }

                ft::pair<iterator, bool> insert(const value_type & val) {
                    return (m_tree.insert(val));
                }

                iterator insert(iterator position, const value_type & val) {
                    (void)position;
                    return (m_tree.insert(val).first);
                }

                template < class InputIterator >
                    void insert(InputIterator first, InputIterator last) {
                        for (; first != last; ++first) {
                            m_tree.insert(*first);
                        }
                    }

                void erase(iterator position) {
                    m_tree.erase(position);
                }

                size_type erase(const key_type & k) {
                    return m_tree.erase(k);
                }

                void erase(iterator first, iterator last) {
                    m_tree.erase(first, last);
                }

        };

}

#endif
