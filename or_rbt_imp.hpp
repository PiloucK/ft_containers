// -*- C++ -*-
//===----------------------------- map ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP_MAP
#define _LIBCPP_MAP
/*
    map synopsis
namespace std
{
template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, T>>>
class map
{
public:
    // types:
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef Compare                                  key_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
    class value_compare
        : public binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;
        value_compare(key_compare c);
    public:
        bool operator()(const value_type& x, const value_type& y) const;
    };
    // construct/copy/destroy:
    map();
    explicit map(const key_compare& comp);
    map(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare());
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
    map(const map& m);
    map(map&& m);
    explicit map(const allocator_type& a);
    map(const map& m, const allocator_type& a);
    map(map&& m, const allocator_type& a);
    map(initializer_list<value_type> il, const key_compare& comp = key_compare());
    map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);

   ~map();
    map& operator=(const map& m);
    map& operator=(map&& m);
    map& operator=(initializer_list<value_type> il);
    // iterators:
          iterator begin();
    const_iterator begin() const;
          iterator end();
    const_iterator end()   const;
          reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
          reverse_iterator rend();
    const_reverse_iterator rend()   const;
    // capacity:
    bool      empty()    const;
    size_type size()     const;
    size_type max_size() const;
    // element access:
    mapped_type& operator[](const key_type& k);
    mapped_type& operator[](key_type&& k);
          mapped_type& at(const key_type& k);
    const mapped_type& at(const key_type& k) const;
    // modifiers:
    pair<iterator, bool> insert(const value_type& v);
    template <class P>
        pair<iterator, bool> insert(P&& p);
    iterator insert(const_iterator position, const value_type& v);
    template <class P>
        iterator insert(const_iterator position, P&& p);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);
    iterator  erase(const_iterator position);
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;
    void swap(map& m);
    // observers:
    allocator_type get_allocator() const;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;
    // map operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
      size_type count(const K& x) const;
    size_type      count(const key_type& k) const;
          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
};
template <class Key, class T, class Compare, class Allocator>
bool
operator==(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool
operator< (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool
operator> (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);
// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void
swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y);

// std
*/
#include <__config>
#include <__tree>
#include <iterator>
#include <memory>
#include <utility>
#include <functional>
#include <initializer_list>
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

template <class _Key, class _CP, class _Compare, bool = is_empty<_Compare>::value>
class __map_value_compare
    : private _Compare
{

    public:
        __map_value_compare()
            _NOEXCEPT_(is_nothrow_default_constructible<_Compare>::value)
            : _Compare() {}
        __map_value_compare(_Compare c)
            _NOEXCEPT_(is_nothrow_copy_constructible<_Compare>::value)
            : _Compare(c) {}
        const _Compare& key_comp() const  {return *this;}
        bool operator()(const _CP& __x, const _CP& __y) const
            {return static_cast<const _Compare&>(*this)(__x.__cc.first, __y.__cc.first);}
        bool operator()(const _CP& __x, const _Key& __y) const
            {return static_cast<const _Compare&>(*this)(__x.__cc.first, __y);}
        bool operator()(const _Key& __x, const _CP& __y) const
            {return static_cast<const _Compare&>(*this)(__x, __y.__cc.first);}

};

template <class _Key, class _CP, class _Compare>
class __map_value_compare<_Key, _CP, _Compare, false>
{
    _Compare comp;
public:
    __map_value_compare()
        : comp() {}
    __map_value_compare(_Compare c)
        : comp(c) {}
    const _Compare& key_comp() const {return comp;}
    bool operator()(const _CP& __x, const _CP& __y) const
        {return comp(__x.__cc.first, __y.__cc.first);}
    bool operator()(const _CP& __x, const _Key& __y) const
        {return comp(__x.__cc.first, __y);}
    bool operator()(const _Key& __x, const _CP& __y) const
        {return comp(__x, __y.__cc.first);}
};

template <class _Allocator>
class __map_node_destructor
{
    typedef _Allocator                          allocator_type;
    typedef allocator_traits<allocator_type>    __alloc_traits;
    typedef typename __alloc_traits::value_type::value_type value_type;
public:
    typedef typename __alloc_traits::pointer    pointer;
private:
    typedef typename value_type::value_type::first_type     first_type;
    typedef typename value_type::value_type::second_type    second_type;
    allocator_type& __na_;
    __map_node_destructor& operator=(const __map_node_destructor&);
public:
    bool __first_constructed;
    bool __second_constructed;
    explicit __map_node_destructor(allocator_type& __na) 
        : __na_(__na),
          __first_constructed(false),
          __second_constructed(false)
        {}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

    __map_node_destructor(__tree_node_destructor<allocator_type>&& __x) 
        : __na_(__x.__na_),
          __first_constructed(__x.__value_constructed),
          __second_constructed(__x.__value_constructed)
        {
            __x.__value_constructed = false;
        }
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
    
    void operator()(pointer __p) 
    {
        if (__second_constructed)
            __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__cc.second));
        if (__first_constructed)
            __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__cc.first));
        if (__p)
            __alloc_traits::deallocate(__na_, __p, 1);
    }
};

template <class _Key, class _Tp, class _Compare, class _Allocator>
    class map;

template <class _TreeIterator> class __map_const_iterator;

template <class _Key, class _Tp>
struct __value_type
{
    typedef _Key                                     key_type;
    typedef _Tp                                      mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    value_type __cc;
    __value_type() {}
    template <class _A0>
    __value_type(const _A0& __a0)
        : __cc(__a0) {}
    template <class _A0, class _A1>
    __value_type(const _A0& __a0, const _A1& __a1)
        : __cc(__a0, __a1) {}
};

template <class _TreeIterator>
class __map_iterator
{
    _TreeIterator __i_;
    typedef typename _TreeIterator::__pointer_traits             __pointer_traits;
    typedef const typename _TreeIterator::value_type::value_type::first_type __key_type;
    typedef typename _TreeIterator::value_type::value_type::second_type      __mapped_type;
public:
    typedef bidirectional_iterator_tag                           iterator_category;
    typedef pair<__key_type, __mapped_type>                      value_type;
    typedef typename _TreeIterator::difference_type              difference_type;
    typedef value_type&                                          reference;
    typedef typename __pointer_traits::template
#ifndef _LIBCPP_HAS_NO_TEMPLATE_ALIASES
            rebind<value_type>
#else
            rebind<value_type>::other
#endif
                                                                 pointer;

    __map_iterator()  {}
    __map_iterator(_TreeIterator __i)  : __i_(__i) {}
    reference operator*() const {return __i_->__cc;}
    pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__cc);}
    __map_iterator& operator++() {++__i_; return *this;}
    __map_iterator operator++(int)
    {
        __map_iterator __t(*this);
        ++(*this);
        return __t;
    }
    __map_iterator& operator--() {--__i_; return *this;}
    __map_iterator operator--(int)
    {
        __map_iterator __t(*this);
        --(*this);
        return __t;
    }
    friend 
    bool operator==(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ == __y.__i_;}
    friend 
    bool operator!=(const __map_iterator& __x, const __map_iterator& __y)
        {return __x.__i_ != __y.__i_;}
    template <class, class, class, class> friend class  map;
    template <class> friend class  __map_const_iterator;
};

template <class _TreeIterator>
class  __map_const_iterator
{
    _TreeIterator __i_;
    typedef typename _TreeIterator::__pointer_traits             __pointer_traits;
    typedef const typename _TreeIterator::value_type::value_type::first_type __key_type;
    typedef typename _TreeIterator::value_type::value_type::second_type      __mapped_type;
public:
    typedef bidirectional_iterator_tag                           iterator_category;
    typedef pair<__key_type, __mapped_type>                      value_type;
    typedef typename _TreeIterator::difference_type              difference_type;
    typedef const value_type&                                    reference;
    typedef typename __pointer_traits::template
#ifndef _LIBCPP_HAS_NO_TEMPLATE_ALIASES
            rebind<const value_type>
#else
            rebind<const value_type>::other
#endif
                                                                 pointer;

    __map_const_iterator()  {}
    __map_const_iterator(_TreeIterator __i)  : __i_(__i) {}
    __map_const_iterator(
            __map_iterator<typename _TreeIterator::__non_const_iterator> __i)
                : __i_(__i.__i_) {}
    reference operator*() const {return __i_->__cc;}
    pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__cc);}
    __map_const_iterator& operator++() {++__i_; return *this;}
    __map_const_iterator operator++(int)
    {
        __map_const_iterator __t(*this);
        ++(*this);
        return __t;
    }
    __map_const_iterator& operator--() {--__i_; return *this;}
    __map_const_iterator operator--(int)
    {
        __map_const_iterator __t(*this);
        --(*this);
        return __t;
    }
    friend 
    bool operator==(const __map_const_iterator& __x, const __map_const_iterator& __y)
        {return __x.__i_ == __y.__i_;}
    friend 
    bool operator!=(const __map_const_iterator& __x, const __map_const_iterator& __y)
        {return __x.__i_ != __y.__i_;}
    template <class, class, class, class> friend class  map;
    template <class, class, class> friend class  __tree_const_iterator;
};
//________________________________________________________________________________________________________________________________________________________________________________
template <class _Key, class _Tp, class _Compare = less<_Key>,
          class _Allocator = allocator<pair<const _Key, _Tp> > >
class  map
{
public:
    // types:
    typedef _Key                                     key_type;
    typedef _Tp                                      mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef pair<key_type, mapped_type>              __nc_value_type;
    typedef _Compare                                 key_compare;
    typedef _Allocator                               allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    class  value_compare
        : public binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;
         value_compare(key_compare c) : comp(c) {}
    public:
        
        bool operator()(const value_type& __x, const value_type& __y) const
            {return comp(__x.first, __y.first);}
    };

private:
    typedef _VSTD::__value_type<key_type, mapped_type>             __value_type;
    typedef __map_value_compare<key_type, __value_type, key_compare> __vc;
    typedef typename allocator_traits<allocator_type>::template
#ifndef _LIBCPP_HAS_NO_TEMPLATE_ALIASES
            rebind_alloc<__value_type>
#else
            rebind_alloc<__value_type>::other
#endif
                                                           __allocator_type;
    typedef __tree<__value_type, __vc, __allocator_type>   __base;
    typedef typename __base::__node_traits                 __node_traits;
    typedef allocator_traits<allocator_type>               __alloc_traits;
    __base __tree_;

public:
    typedef typename __alloc_traits::pointer               pointer;
    typedef typename __alloc_traits::const_pointer         const_pointer;
    typedef typename __alloc_traits::size_type             size_type;
    typedef typename __alloc_traits::difference_type       difference_type;
    typedef __map_iterator<typename __base::iterator>      iterator;
    typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
    typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
    explicit map(const key_compare& __comp = key_compare())
        : __tree_(__vc(__comp)) {}
    explicit map(const key_compare& __comp, const allocator_type& __a)
        : __tree_(__vc(__comp), __a) {}
    template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l,
            const key_compare& __comp = key_compare())
        : __tree_(__vc(__comp))
        {
            insert(__f, __l);
        }
    template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l,
            const key_compare& __comp, const allocator_type& __a)
        : __tree_(__vc(__comp), __a)
        {
            insert(__f, __l);
        }
    
    map(const map& __m)
        : __tree_(__m.__tree_)
        {
            insert(__m.begin(), __m.end());
        }
    map& operator=(const map& __m)
        {
            if (this != &__m) {
                __tree_.clear();
                __tree_.value_comp() = __m.__tree_.value_comp();
                __tree_.__copy_assign_alloc(__m.__tree_);
                insert(__m.begin(), __m.end());
            }
            return *this;
        }
    
    map& operator=(initializer_list<value_type> __il)
        {
            __tree_.__assign_unique(__il.begin(), __il.end());
            return *this;
        }
    
    explicit map(const allocator_type& __a)
        : __tree_(__a)
        {
        }
    map(const map& __m, const allocator_type& __a)
        : __tree_(__m.__tree_.value_comp(), __a)
        {
            insert(__m.begin(), __m.end());
        }
          iterator begin()  {return __tree_.begin();}
    const_iterator begin() const  {return __tree_.begin();}
          iterator end()  {return __tree_.end();}
    const_iterator end() const  {return __tree_.end();}
          reverse_iterator rbegin()  {return reverse_iterator(end());}
    const_reverse_iterator rbegin() const 
        {return const_reverse_iterator(end());}
          reverse_iterator rend() 
            {return       reverse_iterator(begin());}
    const_reverse_iterator rend() const 
        {return const_reverse_iterator(begin());}
    bool      empty() const  {return __tree_.size() == 0;}
    size_type size() const  {return __tree_.size();}
    size_type max_size() const  {return __tree_.max_size();}
    mapped_type& operator[](const key_type& __k);
          mapped_type& at(const key_type& __k);
    const mapped_type& at(const key_type& __k) const;
    allocator_type get_allocator() const  {return __tree_.__alloc();}
    key_compare    key_comp()      const {return __tree_.value_comp().key_comp();}
    value_compare  value_comp()    const {return value_compare(__tree_.value_comp().key_comp());}    
    pair<iterator, bool>
        insert(const value_type& __v) {return __tree_.__insert_unique(__v);}
    iterator
        insert(const_iterator __p, const value_type& __v)
            {return __tree_.__insert_unique(__p.__i_, __v);}
    template <class _InputIterator>
        
        void insert(_InputIterator __f, _InputIterator __l)
        {
            for (const_iterator __e = end(); __f != __l; ++__f)
                insert(__e.__i_, *__f);
        }
   
    iterator erase(const_iterator __p) {return __tree_.erase(__p.__i_);}
    size_type erase(const key_type& __k)
        {return __tree_.__erase_unique(__k);}
    iterator  erase(const_iterator __f, const_iterator __l)
        {return __tree_.erase(__f.__i_, __l.__i_);}
    void clear()  {__tree_.clear();}
    void swap(map& __m)
        {__tree_.swap(__m.__tree_);}
    iterator find(const key_type& __k)             {return __tree_.find(__k);}
    const_iterator find(const key_type& __k) const {return __tree_.find(__k);}
    
    size_type      count(const key_type& __k) const
        {return __tree_.__count_unique(__k);}
    iterator lower_bound(const key_type& __k)
        {return __tree_.lower_bound(__k);}
    const_iterator lower_bound(const key_type& __k) const
        {return __tree_.lower_bound(__k);}
    
    iterator upper_bound(const key_type& __k)
        {return __tree_.upper_bound(__k);}
    const_iterator upper_bound(const key_type& __k) const
        {return __tree_.upper_bound(__k);}
   
    pair<iterator,iterator> equal_range(const key_type& __k)
        {return __tree_.__equal_range_unique(__k);}
    pair<const_iterator,const_iterator> equal_range(const key_type& __k) const
        {return __tree_.__equal_range_unique(__k);}

private:
    typedef typename __base::__node                    __node;
    typedef typename __base::__node_allocator          __node_allocator;
    typedef typename __base::__node_pointer            __node_pointer;
    typedef typename __base::__node_const_pointer      __node_const_pointer;
    typedef typename __base::__node_base_pointer       __node_base_pointer;
    typedef typename __base::__node_base_const_pointer __node_base_const_pointer;
    typedef __map_node_destructor<__node_allocator> _Dp;
    typedef unique_ptr<__node, _Dp> __node_holder;
    __node_holder __construct_node_with_key(const key_type& __k);
    __node_base_pointer&
        __find_equal_key(__node_base_pointer& __parent, const key_type& __k);
    __node_base_const_pointer
        __find_equal_key(__node_base_const_pointer& __parent, const key_type& __k) const;
};
// Find place to insert if __k doesn't exist
// Set __parent to parent of null leaf
// Return reference to null leaf
// If __k exists, set parent to node of __k and return reference to node of __k
template <class _Key, class _Tp, class _Compare, class _Allocator>
typename map<_Key, _Tp, _Compare, _Allocator>::__node_base_pointer&
map<_Key, _Tp, _Compare, _Allocator>::__find_equal_key(__node_base_pointer& __parent,
                                                       const key_type& __k)
{
    __node_pointer __nd = __tree_.__root();
    if (__nd != nullptr)
    {
        while (true)
        {
            if (__tree_.value_comp().key_comp()(__k, __nd->__value_.__cc.first))
            {
                if (__nd->__left_ != nullptr)
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                else
                {
                    __parent = static_cast<__node_base_pointer>(__nd);
                    return __parent->__left_;
                }
            }
            else if (__tree_.value_comp().key_comp()(__nd->__value_.__cc.first, __k))
            {
                if (__nd->__right_ != nullptr)
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                else
                {
                    __parent = static_cast<__node_base_pointer>(__nd);
                    return __parent->__right_;
                }
            }
            else
            {
                __parent = static_cast<__node_base_pointer>(__nd);
                return __parent;
            }
        }
    }
    __parent = static_cast<__node_base_pointer>(__tree_.__end_node());
    return __parent->__left_;
}
// Find __k
// Set __parent to parent of null leaf and
//    return reference to null leaf iv __k does not exist.
// If __k exists, set parent to node of __k and return reference to node of __k
template <class _Key, class _Tp, class _Compare, class _Allocator>
typename map<_Key, _Tp, _Compare, _Allocator>::__node_base_const_pointer
map<_Key, _Tp, _Compare, _Allocator>::__find_equal_key(__node_base_const_pointer& __parent,
                                                       const key_type& __k) const
{
    __node_const_pointer __nd = __tree_.__root();
    if (__nd != nullptr)
    {
        while (true)
        {
            if (__tree_.value_comp().key_comp()(__k, __nd->__value_.__cc.first))
            {
                if (__nd->__left_ != nullptr)
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                else
                {
                    __parent = static_cast<__node_base_pointer>(__nd);
                    return const_cast<const __node_base_const_pointer&>(__parent->__left_);
                }
            }
            else if (__tree_.value_comp().key_comp()(__nd->__value_.__cc.first, __k))
            {
                if (__nd->__right_ != nullptr)
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                else
                {
                    __parent = static_cast<__node_base_pointer>(__nd);
                    return const_cast<const __node_base_const_pointer&>(__parent->__right_);
                }
            }
            else
            {
                __parent = static_cast<__node_base_pointer>(__nd);
                return __parent;
            }
        }
    }
    __parent = static_cast<__node_base_pointer>(__tree_.__end_node());
    return const_cast<const __node_base_const_pointer&>(__parent->__left_);
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
typename map<_Key, _Tp, _Compare, _Allocator>::__node_holder
map<_Key, _Tp, _Compare, _Allocator>::__construct_node_with_key(const key_type& __k)
{
    __node_allocator& __na = __tree_.__node_alloc();
    __node_holder __h(__node_traits::allocate(__na, 1), _Dp(__na));
    __node_traits::construct(__na, _VSTD::addressof(__h->__value_.__cc.first), __k);
    __h.get_deleter().__first_constructed = true;
    __node_traits::construct(__na, _VSTD::addressof(__h->__value_.__cc.second));
    __h.get_deleter().__second_constructed = true;
    return _VSTD::move(__h);  // explicitly moved for C++03
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
_Tp&
map<_Key, _Tp, _Compare, _Allocator>::operator[](const key_type& __k)
{
    __node_base_pointer __parent;
    __node_base_pointer& __child = __find_equal_key(__parent, __k);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == nullptr)
    {
        __node_holder __h = __construct_node_with_key(__k);
        __tree_.__insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
        __r = __h.release();
    }
    return __r->__value_.__cc.second;
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator==(const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator< (const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator!=(const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__x == __y);
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator> (const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return __y < __x;
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator>=(const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__x < __y);
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
bool
operator<=(const map<_Key, _Tp, _Compare, _Allocator>& __x,
           const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__y < __x);
}
template <class _Key, class _Tp, class _Compare, class _Allocator>
inline 
void
swap(map<_Key, _Tp, _Compare, _Allocator>& __x,
     map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    __x.swap(__y);
}

#endif  // _LIBCPP_MAP
