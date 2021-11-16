#ifndef DEBUG_HPP
# define DEBUG_HPP

# ifdef DEBUG
# 	define ASSERT(T) if (!(T)) { std::cerr << "\033[1;31mASSERT FAILED\033[0m " #T << std::endl; exit(1); }
# else
# 	define ASSERT(T)
# endif

#endif
