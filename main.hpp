#ifndef MAIN_HPP
# define MAIN_HPP

# include "myUnitTest.hpp"

# if USING_STD
#  define VECTOR std::vector
#  include <vector>
# else
#  define VECTOR ft::Vector
#  include "Vector.hpp"
# endif

#endif
