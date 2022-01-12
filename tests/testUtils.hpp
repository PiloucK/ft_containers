#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

# define DISTANCE std::distance

# if USING_STD
#  define NAMESPACE std
#  define VECTOR std::vector
#  include <vector>
#  define STACK std::stack
#  include <stack>
# endif

# if USING_FT
#  define NAMESPACE ft
#  define VECTOR ft::Vector
#  include "Vector.hpp"
#  define STACK ft::Stack
#  include "Stack.hpp"
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
		return (out << "Aware(" << aware.object() << ");");
	}

#endif
