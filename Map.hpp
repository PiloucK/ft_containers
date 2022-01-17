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
                typedef RedBlackTree<Key, T, Compare>                   tree_type;

            public:
                typedef Key                                             key_type;
                typedef T                                               mapped_type;
                typedef ft::pair<const key_type, mapped_type>           value_type;
                typedef Compare                                         key_compare;
                typedef Alloc                                           allocator_type;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::const_reference        const_reference;
                typedef typename allocator_type::pointer                pointer;
                typedef typename allocator_type::const_pointer          const_pointer;
                typedef std::ptrdiff_t                                  difference_type;
                typedef std::size_t                                          size_type;
                typedef RedBlackIterator<value_type>                    iterator;
                typedef RedBlackConstIterator<value_type>               const_iterator;
                typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
                typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

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
                allocator_type     m_allocator;
                key_compare        m_key_comparator;
                tree_type          m_tree;

            public:
                explicit Map(
                    const key_compare & comp = key_compare()
                    , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_key_comparator(comp)
                        , m_tree(comp)
                {}

                template < class InputIterator >
                    Map(
                        InputIterator first
                        , InputIterator last
                        , const key_compare & comp = key_compare()
                        , const allocator_type & alloc = allocator_type())
                        : m_allocator(alloc)
                        , m_key_comparator(comp)
                        , m_tree(comp)
                {
                    insert(first, last);
                }

                Map(
                    const Map & x)
                        : m_allocator(x.m_allocator)
                        , m_key_comparator(x.m_key_comparator)
                        , m_tree(x.m_tree)
                {
                    insert(x.m_tree.begin(), x.m_tree.end());
                }

                Map & operator = (const Map & x) {
                    m_tree = x.m_tree;
                    return (*this);
                }

                ~Map()
                {
                    m_tree.destroy_at_root();
                }

                allocator_type get_allocator() const {
                    return (m_allocator);
                }

                key_compare key_comp() const {
                    return (m_key_comparator);
                }

                value_compare value_comp() const {
                    return value_compare(m_key_comparator);
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

                const_iterator find(const key_type & k) const {
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

                ft::pair<iterator, iterator> equal_range(const key_type & k) {
                    return (m_tree.equal_range(k));
                }

                ft::pair<const_iterator, const_iterator> equal_range(const key_type & k) const {
                    return (m_tree.equal_range(k));
                }

                iterator lower_bound(const key_type & k) {
                    return (m_tree.lower_bound(k));
                }

                const_iterator lower_bound(const key_type & k) const {
                    return (m_tree.lower_bound(k));
                }

                iterator upper_bound(const key_type & k) {
                    return (m_tree.upper_bound(k));
                }

                const_iterator upper_bound(const key_type & k) const {
                    return (m_tree.upper_bound(k));
                }

                mapped_type & operator [] (const key_type & k) {
                    return ((*(insert(ft::make_pair(k, mapped_type())).first)).second);
                }

                void swap(Map & x) {
                    m_tree.swap(x.m_tree);
                    std::swap(m_allocator, x.m_allocator);
                    std::swap(m_key_comparator, x.m_key_comparator);
                }

            private:
                void print() const {
                    m_tree.print();
                }

                void print(iterator first) {
                    m_tree.print(first);
                }

        };

    template < class Key, class T, class Compare, class Alloc >
        bool operator == (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return (lhs.size() == rhs.size()
                && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
        }

    template < class Key, class T, class Compare, class Alloc >
        bool operator != (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return (!(lhs == rhs));
        }

    template < class Key, class T, class Compare, class Alloc >
        bool operator < (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(). rhs.end()));
        }

    template < class Key, class T, class Compare, class Alloc >
        bool operator <= (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return (!(rhs < lhs));
        }

    template < class Key, class T, class Compare, class Alloc >
        bool operator > (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return ((rhs < lhs));
        }

    template < class Key, class T, class Compare, class Alloc >
        bool operator >= (const Map<Key, T, Compare, Alloc> & lhs
                        , const Map<Key, T, Compare, Alloc> & rhs) {
            return (!(lhs < rhs));
        }

    template < class Key, class T, class Compare, class Alloc >
        void swap(Map<Key, T, Compare, Alloc> & x, Map<Key, T, Compare, Alloc> & y) {
            x.swap(y);
        }

}

#endif
