# include "main.hpp"

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

cases_map_t g_test_cases;
int g_aware_count = 0;

int main( void )
{
  TESTABLE_RUN(Vector)
  TESTABLE_RUN(Stack)
  TESTABLE_RUN(Map)
}
