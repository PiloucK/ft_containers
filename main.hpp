#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include "debug.hpp"

# define CLEAR_STDOUT std::cout << "\033[2J";
# define WAIT_INPUT std::cin.get();
# define START_INFO std::cout << "To start the tests or go to the next one, press ENTER\n";
# define NEXT_TEST std::cin.get(); std::cout << "\033[2J"; std::cout << "To start the tests or go to the next one, press ENTER\n\n\n";

# define MAX_VAL 750

#endif
