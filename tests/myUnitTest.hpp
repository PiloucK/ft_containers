/*!
  @file myUnitTest.hpp
  @author Clément Kuzniewycz (clkuznie@student.42.fr)
  @brief 
  @version 0.1
  @date 2021-11-21
  
  @copyright Copyright (c) 2021
  
 */
#ifndef MY_UNIT_TEST_HPP
# define MY_UNIT_TEST_HPP

# include <iostream>
# include <cstdlib>
# include <sys/wait.h>
# include <sys/types.h>

# define TEST_CASES_BEGIN(TestSuite, TestName) \
    void test_##TestSuite##_##TestName( void ) \
    { \
        pid_t pid = fork(); \

        if (pid < 0) { \
            std::cout \
                << "    |   |-- " << "Out of testing error:\n" \
                << "    |   |-- " << __func__ << " failed to create a process\n"; \
            return ; \
        } else if (pid != 0) { \
            return ; \
        } else { \
            int test_passed = 0; \
            int test_failed = 0; \

# define TEST_CASES_END \
            std::cout \
                << "    |   |-- " << #TestSuite; << "\n" \
                << "    |   |    |-- " << "Passed: " << test_passed; << "\n" \
                << "    |   |    |-- " << "Failed: " << test_failed; << "\n" \
        } \
        \
        exit(EXIT_SUCCESS); \
    } \

# define TEST_SUITE_BEGIN(Testable, TestSuite) \
    void test_##Testable##_##TestSuite( void ) \
    { \
        std::cout \
            << "\n    |-- " << "Testing for " << #TestSuite << "\n"; \

# define TEST_SUITE_END \
        waitpid(0, NULL, 0); \
    } \

# define TESTABLE(Testable) std::cout << #Testable << "\n";

#endif
