#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

# define DISTANCE std::distance

# if USING_STD
#  define VECTOR std::vector
#  include <vector>
# endif

# if USING_FT
#  define VECTOR ft::Vector
#  include "Vector.hpp"
# endif

# define ARR_ARGS(...) __VA_ARGS__
# define INIT_ARR(VAR_NAME,ARR_DATA) VAR_NAME = {ARR_ARGS ARR_DATA}

extern int g_aware_count;

template<class T>
class Aware {

    public:
		Aware() : m_object(0) {
            // std::cerr << "Aware default ctor: " << __func__ << " | " << __LINE__ << " | " << g_aware_count << "\n";
			g_aware_count++;
		}

        Aware(T object) : m_object(object) {
            // std::cerr << "Aware value ctor: " << __func__ << " | " << __LINE__ << " | " << g_aware_count << "\n";
            g_aware_count++;
        }

        Aware(const Aware & model) : m_object(model.m_object) {
            // std::cerr << "Aware copy ctor: " << __func__ << " | " << __LINE__ << " | " << g_aware_count << "\n";
            g_aware_count++;
        }

        ~Aware() {
            // std::cerr << "Aware dtor: " << __func__ << " | " << __LINE__ << " | " << g_aware_count << "\n";
            g_aware_count--;
        }

        Aware & operator = (const Aware & right) {
            m_object = right.m_object;
            return *this;
        }

        bool operator == (const Aware & right) const {
            return (m_object == right.m_object);
        }

        bool operator < (const Aware & right) const {
            return (m_object < right.m_object);
        }

        bool operator > (const Aware & right) const {
            return (m_object > right.m_object);
        }

        bool operator != (const Aware & right) const {
            return (m_object != right.m_object);
        }

        bool operator <= (const Aware & right) const {
            return (m_object <= right.m_object);
        }

        bool operator >= (const Aware & right) const {
            return (m_object >= right.m_object);
        }

        T & operator [] (size_t n) {
            return (m_object[n]);
        }

        const T & object(void) const {
            return (m_object);
        }

    private:
        T m_object;

};

template<class T>
	std::ostream&
	operator <<(std::ostream & out, const Aware<T> & aware)
	{
		return (out << "Aware(" << aware.x() << ");");
	}

// template<typename T>
// 	class SimpleIterator :
// 			public ft::iterator<RANDOM_ACCESS_ITERATOR_TAG, T>
// 	{
// 		private:
// 			typedef typename ITERATOR_TRAITS<T> traits;

// 		public:
// 			typedef typename traits::iterator_category iterator_category;
// 			typedef typename traits::value_type value_type;
// 			typedef typename traits::difference_type difference_type;
// 			typedef typename traits::reference reference;
// 			typedef typename traits::pointer pointer;

// 		private:
// 			T _ptr;

// 		public:
// 			SimpleIterator() : _ptr(NULL) {
// 			}

// 			SimpleIterator(const T &ptr) : _ptr(ptr) {
// 			}

// 			virtual ~SimpleIterator() {
// 			}

// 			SimpleIterator & operator ++ () {
// 				_ptr++;

// 				return (*this);
// 			}

// 			SimpleIterator
// 			operator++(int)
// 			{
// 				SimpleIterator cpy(_ptr);

// 				_ptr++;

// 				return (cpy);
// 			}

// 			SimpleIterator&
// 			operator--()
// 			{
// 				_ptr--;

// 				return (*this);
// 			}

// 			SimpleIterator
// 			operator--(int)
// 			{
// 				SimpleIterator cpy(_ptr);

// 				_ptr--;

// 				return (cpy);
// 			}

// 			reference operator * () const {
// 				return (*_ptr);
// 			}

// 			pointer operator -> () const {
// 				return (_ptr);
// 			}

// 			bool operator == (const SimpleIterator &rhs) const {
// 				return (_ptr == rhs._ptr);
// 			}

// 			bool operator != (const SimpleIterator &rhs) const {
// 				return (_ptr != rhs._ptr);
// 			}

// 			bool operator < (const SimpleIterator &rhs) const {
// 				return (_ptr < rhs._ptr);
// 			}

// 			bool operator > (const SimpleIterator &rhs) const {
// 				return (_ptr > rhs._ptr);
// 			}

// 			bool operator <= (const SimpleIterator &rhs) const {
// 				return (_ptr <= rhs._ptr);
// 			}

// 			bool operator >= (const SimpleIterator &rhs) const {
// 				return (_ptr >= rhs._ptr);
// 			}

// 			const pointer base() const {
// 				return (_ptr);
// 			}
// 	};

// template<class T>
// 	typename SimpleIterator<T>::difference_type
// 	operator - (const SimpleIterator<T> &left, const SimpleIterator<T> &right) {
// 		return (left.base() - right.base());
// 	}

#endif
