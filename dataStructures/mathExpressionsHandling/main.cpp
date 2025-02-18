#include <iostream>
#include <vector>
#include "mathExpressionsHandling.hpp"
#include "testMathExpressionsHandling.cpp"

int main()
{
    ExpressionsHandling exprHandling;
    std::vector<std::string> singleDigitInfix = {
        "2+3",
        "2+3-1",
        "2+3*5",
        "2+3-1*5",
        "2+3*5-1",
        "2 + 3 * 5 / 4",
        "2 + 3 - 1 * 5 / 4",
        "2 + 3 * 5 - 1 / 4",
        "2 ** 2 + 3",
        "2 ** 2 + 3 - ( 8 * ( 5 + 7 ) ) / 4"};

    std::vector<std::string> singleDigitPrefix = {
        "+ 2 3",
        "- + 2 3 1",
        "+ 2 * 3 5",
        "- + 2 3 * 1 5",
        "- + 2 * 3 5 1",
        "+ 2 / * 3 5 4",
        "- + 2 3 / * 1 5 4",
        "- + 2 * 3 5 / 1 4",
        "+ ** 2 2 3",
        "- + ** 2 2 3 / * 8 + 5 7 4"};

    std::vector<std::string> singleDigitPostfix = {
        "2 3 +",
        "2 3 + 1 -",
        "2 3 5 * +",
        "2 3 + 1 5 * -",
        "2 3 5 * + 1 -",
        "2 3 5 * 4 / +",
        "2 3 + 1 5 * 4 / -",
        "2 3 5 * + 1 4 / -",
        "2 2 ** 3 +",
        "2 2 ** 3 + 8 5 7 + * 4 / -"};

    std::vector<std::string> multidigitInfix = {
        "21 + 3",
        "2 + 73 - 1",
        "2 + 39 * 150",
        "52 + 333 - 11 * 25",
        "2 + 43 * 85 - 3681",
        "25289 + 3 * 35 / 94",
        "2 + 33 - 1 * 55 / 24",
        "82 + 3 * 5 - 71 / 4",
        "22 ** 2 + 23",
        "12 ** 3 + 63 - ( 18 * ( 2 - 3 * 5 + 27 ) ) / 4"};

    std::vector<std::string> multidigitPrefix = {
        "+ 21 3",
        "- + 2 73 1",
        "+ 2 * 39 150",
        "- + 52 333 * 11 25",
        "- + 2 * 43 85 3681",
        "+ 25289 / * 3 35 94",
        "- + 2 33 / * 1 55 24",
        "- + 82 * 3 5 / 71 4",
        "+ ** 22 2 23",
        "- + ** 12 3 63 / * 18 + - 2 * 3 5 27 4"};

    std::vector<std::string> multidigitPostfix = {
        "21 3 +",
        "2 73 + 1 -",
        "2 39 150 * +",
        "52 333 + 11 25 * -",
        "2 43 85 * + 3681 -",
        "25289 3 35 * 94 / +",
        "2 33 + 1 55 * 24 / -",
        "82 3 5 * + 71 4 / -",
        "22 2 ** 23 +",
        "12 3 ** 63 + 18 2 3 5 * - 27 + * 4 / -"};

    std::cout << "[----------Convert singleDigitInfix to prefix:----------]\n";
    runExpressionTests(singleDigitInfix, singleDigitPrefix, &exprHandling, &ExpressionsHandling::toPrefix);

    std::cout << "\n[----------Convert multidigitInfix to prefix:----------]\n";
    runExpressionTests(multidigitInfix, multidigitPrefix, &exprHandling, &ExpressionsHandling::toPrefix);

    return 0;
}