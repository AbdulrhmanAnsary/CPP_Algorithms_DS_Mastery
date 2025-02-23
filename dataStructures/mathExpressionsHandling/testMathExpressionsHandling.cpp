#include <iostream>
#include <vector>
#include <chrono>
#include "mathExpressionsHandling.hpp"

// Function: runExpressionTests
// Purpose: Tests an ExpressionsHandling method against multiple test cases.
// Parameters:
//   testCases           - A vector of input strings representing each test case.
//   testCasesExpected   - A vector of expected output strings corresponding to each test case.
//   object              - A pointer to an instance of ExpressionsHandling that processes the test cases.
//   method              - A pointer-to-member function of ExpressionsHandling which takes a const string reference
//                         and returns a string. This function will be used to process each test case.
void runExpressionTests(const std::vector<std::string> &testCases, const std::vector<std::string> &testCasesExpected, ExpressionsHandling *object, std::string (ExpressionsHandling::*method)(const std::string &))
{
    int successCounter = 0;
    int failCounter = 0;
    double totalTestTime = 0.0;
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        // Record the starting time for this test case
        auto startTime = std::chrono::steady_clock::now();

        // Call the member function 'method' on the provided object with the current test case as argument
        // The syntax (object->*method)(testCases[i]) calls the method pointed to by 'method' on 'object'
        std::string result = (object->*method)(testCases[i]);

        // Record the ending time for this test case
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the time taken for this test case in milliseconds
        double testTime = std::chrono::duration<double, std::milli>(endTime - startTime).count();
        totalTestTime += testTime;

        if (testCasesExpected[i] == result)
        {
            std::cout << "\033[32m"; // Set console output color to green for a successful test
            std::cout << "\nTest " << i + 1 << ": passed in (" << testTime << ") ms\n";
            successCounter++;
        }
        else
        {
            std::cout << "\033[31m"; // Set console output color to red for a failed test
            std::cout << "\n[============================================================]\n";
            std::cout << "  Test " << i + 1 << ": false because:\n"
                      << std::endl;
            std::cout << "    Expected: " << testCasesExpected[i] << std::endl;
            std::cout << "    Length: " << size(testCasesExpected[i]) << std::endl
                      << std::endl;
            std::cout << "    Actual: " << result << std::endl;
            std::cout << "    Length: " << size(result) << std::endl
                      << std::endl;
            std::cout << "    The test run in (" << testTime << ") ms" << std::endl;
            std::cout << "[============================================================]\n";
            failCounter++;
        }
    }

    // After processing all tests, set console output color to red if there were failures or green if all tests passed
    failCounter != 0 ? std::cout << "\033[31m" << std::endl : std::cout << "\033[32m" << std::endl;
    std::cout << "Total time: (" << totalTestTime << ") ms\n\n";

    // Print a summary of passed tests in green
    std::cout << "\033[32m";
    std::cout << "[  PASSED  ] " << successCounter << " tests\n";

    // Print a summary of failed tests in red (if any)
    std::cout << "\033[31m";
    failCounter != 0 ? std::cout << "[  FAILED  ] " << failCounter << " tests\n" : std::cout << "";

    // Final summary message: set console output color to red if any test failed or green if all tests passed
    failCounter != 0 ? std::cout << "\033[31m" : std::cout << "\033[32m";
    std::cout << "\npassed " << successCounter << " from " << testCases.size() << " tests\n";

    std::cout << "\033[97m"; // Reset the console output color to white (default)
}
