/*!
  @file myUnitTest.hpp
  @author Clément Kuzniewycz (clkuznie@student.42.fr)
  @brief Minimal macro based framework for c++ unit testing
  @version 0.1
  @date 2021-11-21
  
  @copyright Copyright (c) 2021
  
  OUTDATED DOC, WORK IN PROGRESS

  Complete header for a minimal c++ unit test framework.
  Developped to test individual functions

  The point is to define all the macros for a usefull and still minimal amount
  of code to add to a project for the testing.

  This little self sufficient header allows you to define readable testing suites
  and testing cases. The only requirements being c++ compilation and including
  "myUnitTest.hpp" at the top of your testing program.

  The first step will be to declare the test cases and test suites.
  It is recommended to create a header file for each of the suites you want to
  have. Inside of which all the cases related to the suite will get declared
  with the suite itself. This step is important to have a multiple files testing
  setup and increase overall clarity.
  Declaration works by using SUITE_DECLARE and CASE_DECLARE. Both of which
  generate the same function name as TEST_SUITE_BEGIN and TEST_CASE_BEGIN if
  only the 'Testable', 'TestSuite' and 'TestName' are the same.

  Inside of your case declaration header you have to include the declaration
  of tested function either through including the correct header file or
  writing the much needed prototypes.

  For each of the declared cases, use TEST_CASE_BEGIN and TEST_CASE_END as
  opening and closing brackets. All the actual testing is to be writen between
  those macros using the different 'EXPECT_*' defined here.
  I still recommend using a new scope (example bellow).
  Case example:
  `
    TEST_CASE_BEGIN(std::plus, ParamsConsistency) {
        int a = 9, b = 3;
        std::plus(a, b);

        EXPECT_EQ(a, 9);
        EXPECT_EQ(b, 3);
    } TEST_CASE_END
  `
  After that, between TEST_SUITE_BEGIN and TEST_SUITE_END you only need to
  use TEST_CASE_RUN for each of the cases you want to include in the suite.
  Every suite then has to be called using TEST_SUITE_RUN either in your main
  or the choosen function which will run the appropriate suites.
  Suite example:
  `
    TEST_SUITE_BEGIN(std, std::plus) {
        TEST_CASE_RUN(std::plus, ParamsConsistency)
        ...
    } TEST_SUITE_END
  `

  All of the display for failed or passed tests is in the 'TEST_CASE_END' macro.
  Counting failed or passed test is done through ASSERT implementation which gets
  used in any EXPECT you can use.

  All of the cases blocks are in separate processes which limits the maximum number
  of cases you can use in a suite (suite which waits for cases process ending).

  To use this framework I recommend you to start with the TESTABLE macro as
  first inclassion to print the testable you'll work on. This makes the results
  display way clearer as suites and cases have a default indentation based on
  a visual repository tree.
  Output example:
  `
    std
        |-- Testing for std::plus
        |   |-- ParamsConsistency
        |   |   |-- passed: 2
        |   |   |-- failed: 0
  `

 */
#ifndef MY_UNIT_TEST_HPP
# define MY_UNIT_TEST_HPP

# include <iostream>
# include <cstdlib>
# include <sys/wait.h>
# include <sys/types.h>
# include <string>
# include <unistd.h>
# include <sstream>
# include <map>
# include <list>

# include "testUtils.hpp"

class TestCase;

typedef std::map<const std::string, std::map<const std::string, std::map<const std::string, TestCase> > > cases_map_t;
extern cases_map_t g_test_cases;

class TestCase {

    public:
        const std::string m_testable;
        const std::string m_suite;
        const std::string m_name;
        const std::string m_file;
        std::string m_output_string;
        pid_t m_pid;
        int m_exit_status;
        void (* const m_run)(void);

        TestCase(
            const std::string testable
            , const std::string suite
            , const std::string name
            , const std::string file
            , void (* const run)(void))
                : m_testable(testable)
                , m_suite(suite)
                , m_name(name)
                , m_file(file)
                , m_output_string()
                , m_pid()
                , m_exit_status()
                , m_run(run)
        {
            g_test_cases[m_testable][m_suite].insert(std::make_pair(m_name, *this));
        }

        ~TestCase() {};

};

# define TESTABLE_RUN(Testable)         \
    std::cout << #Testable << "\n";                                                   \
    for (std::map <const std::string, std::map<const std::string, class TestCase> >::iterator suite_it = g_test_cases[#Testable].begin(); \
        suite_it != g_test_cases[#Testable].end(); \
        suite_it++) \
    { \
        TEST_SUITE_RUN_IMPL(Testable, suite_it->first); \
    }



// {                                                                                \
//     std::stringstream output_string;                                             \
//     output_string                                                                \
//         << "    |--- "                                                            \
//         << "Testing for "                                                        \
//         << #TestSuite                                                            \
//         << "\n";                                                                 \
//     std::cout << output_string.str();                                            \
// }
// {                                                                                \
//     std::stringstream output_string;                                             \
//     output_string                                                                \
//         << "    |--- "                                                            \
//         << "Testing for "                                                        \
//         << TestSuite                                                            \
//         << "\n";                                                                 \
//     std::cout << output_string.str();                                            \
// }                                                                                



# define TEST_SUITE_RUN(Testable, TestSuite)                                        \
    {                                                                                    \
        {                                                                                \
            for (std::map<const std::string, class TestCase>::iterator case_it = g_test_cases[#Testable][#TestSuite].begin(); \
                case_it != g_test_cases[#Testable][#TestSuite].end();\
                case_it++) \
            {   \
                case_it->second.m_run();                                                             \
                waitpid(-1, NULL, WUNTRACED);                                                             \
            } \
        }                                                                                \
    }

# define TEST_SUITE_RUN_IMPL(Testable, TestSuite)                                        \
    {                                                                                    \
        {                                                                                \
            for (std::map<const std::string, class TestCase>::iterator case_it = g_test_cases[#Testable][TestSuite].begin(); \
                case_it != g_test_cases[#Testable][TestSuite].end();\
                case_it++) \
            {   \
                case_it->second.m_run();                                                             \
                waitpid(-1, NULL, WUNTRACED);                                                             \
            } \
        }                                                                                \
    }

# define TEST_CASE(Testable, TestSuite, TestName, Content)                                         \
    void test_##Testable##_##TestSuite##_##TestName( void );                                          \
    TestCase g_test_##Testable##_##TestSuite##_##TestName(#Testable, #TestSuite, #TestName, __FILE__, &test_##Testable##_##TestSuite##_##TestName); \
    void test_##Testable##_##TestSuite##_##TestName( void )                              \
    {                                                                                    \
        g_test_cases[#Testable][#TestSuite].find(#TestName)->second.m_pid = fork();                                                       \
        if (g_test_cases[#Testable][#TestSuite].find(#TestName)->second.m_pid < 0) {                                                             \
            std::stringstream output_string;                                             \
            output_string                                                                \
                << "    |    |--- " << "Out of testing error:\n";                           \
            std::cout << output_string.str();                                            \
        } else if (g_test_cases[#Testable][#TestSuite].find(#TestName)->second.m_pid == 0) {                                                     \
            std::stringstream output_string;                                             \
            output_string                                                                \
                << "    |    |--- " << #TestName << "\n";                                  \
            int test_passed = 0;                                                         \
            int test_failed = 0;                                                         \
            {                                                                            \
                Content                                                                  \
            }                                                                            \
            output_string                                                                \
                << "    |    |    |--- " << "Passed: " << test_passed << "\n"              \
                << "    |    |    |--- " << "Failed: " << test_failed << "\n";             \
            std::cout << output_string.str();                                            \
            exit(EXIT_SUCCESS);                                                          \
        }                                                                                \
    }

# define OUTPUT_FAILED_ASSERT(T)                                                         \
    output_string                                                                        \
        << "\033[1;31mASSERT FAILED\033[0m " #T << " | line: " << __LINE__ << "\n";

# define ASSERT(T)                                                                       \
    if (!(T)) {                                                                          \
        OUTPUT_FAILED_ASSERT(T)                                                          \
        test_failed++;                                                                   \
    } else {                                                                             \
        test_passed++;                                                                   \
    }

# define ASSERT_EXCEPT(param)                                                            \
    try {                                                                                \
        param;                                                                           \
        OUTPUT_FAILED_ASSERT(param);                                                     \
        test_failed++;                                                                   \
    } catch (std::exception & e) {                                                       \
        test_passed++;                                                                   \
    }

# define ASSERT_NOEXCEPT(param)                                                          \
    try {                                                                                \
        param;                                                                           \
        test_passed++;                                                                   \
    } catch (std::exception & e) {                                                       \
        OUTPUT_FAILED_ASSERT(param);                                                     \
        test_failed++;                                                                   \
    }

#define ASSERT_AWARENESS                                                                 \
    if (g_aware_count != 0) {                                                             \
        OUTPUT_FAILED_ASSERT(g_aware_count == 0)                                          \
    }                                                                                    \
    g_aware_count = 0;

#endif
