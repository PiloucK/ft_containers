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

# define TARGET(Testable) std::cout << #Testable << "\n";

# define TEST_SUITE_BEGIN(Testable, TestSuite) \
    void test_##Testable##_##TestSuite( void ) \
    { \
        std::cout \
            << "\n    |-- " << "Testing for " << #TestSuite << "\n"; \

# define TEST_SUITE_END \
        waitpid(0, NULL, 0); \
    } \

# define SUITE_RUN(Testable, TestSuite) \
    test_##Testable##_##TestSuite(); \

# define TEST_CASE_BEGIN(TestSuite, TestName) \
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

# define TEST_CASE_END \
            std::cout \
                << "    |   |-- " << #TestSuite; << "\n" \
                << "    |   |    |-- " << "Passed: " << test_passed; << "\n" \
                << "    |   |    |-- " << "Failed: " << test_failed; << "\n" \
        } \
        \
        exit(EXIT_SUCCESS); \
    } \

# define CASE_RUN(TestSuite, TestName) \
    test_##TestSuite##_##testName(); \

# define ASSERT(T) \
    if (!(T)) { \
        std::cout \
            << "\033[1;31mASSERT FAILED\033[0m " #T << "\n"; \
        test_passed++;
    } else { \
        test_failed++; \
    } \

# define ASSERT(T, Tested) \
    if (!(T)) { \
        std::cout \
            << "\033[1;31mASSERT FAILED\033[0m " #Tested << "\n"; \
        test_passed++;
    } else { \
        test_failed++; \
    } \

# define EXPECT_EQ(param1, param2) \
    ASSERT(param1 == param2) \

# define EXPECT_DIFF(param1, param2) \
    ASSERT(param1 != param2) \

# define EXPECT_EXCEPT(param) \
    try { \
        param1; \
        ASSERT(false, param); \
    } catch (std::exception & e) { \
        ASSERT(true, param);
    } \

# define EXPECT_NOEXCEPT(param) \
    try { \
        param1; \
        ASSERT(true, param); \
    } catch (std::exception & e) { \
        ASSERT(false, param);
    } \

    // catch (...) {  \
    //     std::cout \
    //         << "    |   |-- " << "Out of testing error:\n" \
    //         << "    |   |-- " << __func__ << " Unexpected exception\n"; \
    // } \

#endif
