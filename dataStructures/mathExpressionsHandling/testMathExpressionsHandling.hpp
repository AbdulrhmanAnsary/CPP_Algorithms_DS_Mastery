#pragma once

#include <string>
#include <vector>
#include "mathExpressionsHandling.hpp" // For ExpressionsHandling class

// Declaration of the function
void runExpressionTests(
    const std::vector<std::string> &testCases,
    const std::vector<std::string> &testCasesExpected,
    ExpressionsHandling *object,
    std::string (ExpressionsHandling::*method)(const std::string &)
);
