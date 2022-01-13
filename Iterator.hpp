#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {

    // All forward, bidirectional and random-access iterators are also valid input iterators.
    // All bidirectional and random-access iterators are also valid forward iterators.
    // All random-access iterators are also valid bidirectional iterators.
    // These are from cplusplus reference and justify the inheritances bellow, which allow category identification
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template < class Iter >
        struct iterator_traits {
            typedef typename Iter::difference_type difference_type;
            typedef typename Iter::value_type value_type;
            typedef typename Iter::pointer pointer;
            typedef typename Iter::reference reference;
            typedef typename Iter::iterator_category iterator_category;
        };

    template < class T >
        struct iterator_traits<T*> {
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef T * pointer;
            typedef T & reference;
            typedef random_access_iterator_tag iterator_category;
        };

    template < class T >
        struct iterator_traits<const T *> {
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef const T * pointer;
            typedef const T & reference;
            typedef random_access_iterator_tag iterator_category;
        };

    template <class Category              // iterator::iterator_category
            , class T                     // iterator::value_type
            , class Distance = ptrdiff_t  // iterator::difference_type
            , class Pointer = T *         // iterator::pointer
            , class Reference = T &       // iterator::reference
            >
        struct iterator {
            typedef Category iterator_category;
            typedef T value_type;
            typedef Distance difference_type;
            typedef Pointer pointer;
            typedef Reference reference;
        };

    /*!
      @brief Distance between two input iterators
      
      @tparam InputIterator (from template)
      @param first 
      @param last 
      @return iterator_traits<InputIterator>::difference_type which is the result type of the distance

      Here __distance computes the diffence by incrementing the first iterator until it matches the last.
      Allows distance calculation for reverse iterator and any non random access iterators.
     */
    template < class InputIterator >
        typename iterator_traits<InputIterator>::difference_type
        __distance(InputIterator first, InputIterator last, input_iterator_tag) {
            typename iterator_traits<InputIterator>::difference_type result(0);

            for (; first != last; ++first) {
                ++result;
            }

            return (result);
        }

    /*!
      @brief Distance between two random access iterators
      
      @tparam InputIterator (from template)
      @param first 
      @param last 
      @return iterator_traits<InputIterator>::difference_type which is the result type of the distance

      Here __distance computes the diffence through a simple substraction.
      It assumes that a pointer difference can be applied (first is before last).
     */
    template < class InputIterator >
        typename iterator_traits<InputIterator>::difference_type
        __distance(InputIterator first, InputIterator last, random_access_iterator_tag) {
            return (last - first);
        }
    
    template < class InputIterator >
        typename iterator_traits<InputIterator>::difference_type
        distance(InputIterator first, InputIterator last) {
            return(__distance(first, last, typename iterator_traits<InputIterator>::iterator_category()));
        }

    template < class Iterator >
        class reverse_iterator
            : public iterator<typename iterator_traits<Iterator>::iterator_category
                            , typename iterator_traits<Iterator>::value_type
                            , typename iterator_traits<Iterator>::difference_type
                            , typename iterator_traits<Iterator>::pointer
                            , typename iterator_traits<Iterator>::reference>{

            public:
                typedef Iterator iterator_type;
                typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
                typedef typename iterator_traits<Iterator>::value_type value_type;
                typedef typename iterator_traits<Iterator>::difference_type difference_type;
                typedef typename iterator_traits<Iterator>::pointer pointer;
                typedef typename iterator_traits<Iterator>::reference reference;

            protected:
                iterator_type m_base_iterator;

            public:
                reverse_iterator()
                    : m_base_iterator()
                {}

                explicit reverse_iterator(iterator_type x)
                    : m_base_iterator(x)
                {}

                template < class U >
                    reverse_iterator( const reverse_iterator<U> & other )
                        : m_base_iterator(other.base())
                {}

                iterator_type base() const {
                    return (m_base_iterator);
                }

                reference operator * () const {
                    iterator_type m_base_copy(m_base_iterator);
                    return (*--m_base_copy);
                }

                reverse_iterator operator + (difference_type n) const {
                    return (reverse_iterator(m_base_iterator - n));
                }

                reverse_iterator & operator ++ () {
                    --m_base_iterator;
                    return (*this);
                }

                reverse_iterator operator ++ (int) {
                    reverse_iterator tmp(*this);
                    --m_base_iterator;
                    return (tmp);
                }

                reverse_iterator operator += (difference_type n) {
                    m_base_iterator -= n;
                    return (*this);
                }

                reverse_iterator operator - (difference_type n) const {
                    return (reverse_iterator(m_base_iterator + n));
                }

                reverse_iterator & operator -- () {
                    ++m_base_iterator;
                    return (*this);
                }

                reverse_iterator operator -- (int) {
                    reverse_iterator tmp(*this);
                    ++m_base_iterator;
                    return (tmp);
                }

                reverse_iterator operator -= (difference_type n) {
                    m_base_iterator += n;
                    return (*this);
                }
                
                pointer operator -> () const {
                    return (&(operator * ()));
                }

                reference operator [] (difference_type n) const {
                    return (base()[-n-1]);
                }

        };

    template <class Iterator>
        bool operator == (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() == rhs.base());
        }

    template <class Iterator>
        bool operator != (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() != rhs.base());
        }

    template <class Iterator>
        bool operator < (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() > rhs.base());
        }

    template <class Iterator>
        bool operator <= (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() >= rhs.base());
        }

    template <class Iterator>
        bool operator > (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() < rhs.base());
        }

    template <class Iterator>
        bool operator >= (const reverse_iterator<Iterator> & lhs,
                        const reverse_iterator<Iterator> & rhs) {
            return (lhs.base() <= rhs.base());
        }
    
    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type
            operator - (const reverse_iterator<Iterator> & lhs
                        , const reverse_iterator<Iterator> & rhs) {
            return (rhs.base() - lhs.base());
        }

    template <class Iterator>
        reverse_iterator<Iterator>
            operator + (typename reverse_iterator<Iterator>::difference_type n
                        , const reverse_iterator<Iterator> & rev_it) {
            return (reverse_iterator<Iterator>(rev_it.base() - n));
        }

}

#endif
