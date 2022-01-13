/*!
  \file main.cpp
  \author Clément Kuzniewycz (clkuznie@student.42.fr)
  \brief Programm to test ft_containers
  \version 0.1
  \date 2021-11-20

  \copyright Copyright (c) 2021

  Programm testing the methods in ft_containers project through comparison to
  the c++98 standard library implementation.
  The only tested containers are:
       - Vector
       - Stack
       - Map

  \sa myUnitTest.hpp
*/
// #include "myUnitTest.hpp"

# include "main.hpp"

cases_map_t g_test_cases;
int g_aware_count = 0;

int main( void )
{
	// TESTABLE_RUN(Vector)
  // TESTABLE_RUN(Stack)
  // ft::Map<std::string, int>::Node toto;
  // ft::pair<std::string, int> tata("tata", 4);
  // ft::pair<std::string, int> toto("toto", 4);
  // my_map.value_comp()(tata, toto);

  ft::Map<std::string, int> map;
  ft::Map<std::string, int>::iterator it = map.begin();
  // ft::iterator<ft::bidirectional_iterator_tag, ft::pair<const std::string, int> > it = map.begin();
  std::cout << ((*it)->second);
  // ft::pair<std::string, int> toto("toto", 8); 
  // ft::Map<std::string, int>::iterator it(toto);
  // std::cout << it->first;
  // std::cout << " | ";
  // std::cout << (*it).second;
  // std::cout << "\n";
}
