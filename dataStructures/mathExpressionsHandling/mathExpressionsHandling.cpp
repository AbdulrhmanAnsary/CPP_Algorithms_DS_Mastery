#include <algorithm>
#include <stack>
#include "mathExpressionsHandling.hpp"

template <typename T>
bool isNum(const T &expression)
{
    if constexpr (std::is_same_v<T, char>)
        return std::isdigit(static_cast<unsigned char>(expression));
    else if constexpr (std::is_arithmetic_v<T>)
        return true;
    else if constexpr (std::is_same_v<T, std::string>)
        return std::all_of(expression.begin(), expression.end(), [](unsigned char c) {
            return std::isdigit(c);
        });
    else
        return false;
}

// Defining the operators' priorities, where "**" represents the process of the exponent
std::map<std::string, int> OperatorsHandling::operatorsPriority = {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"**", 3}, {"(", 4}, {")", 4}};

bool OperatorsHandling::isOperator(std::string expr)
{
    return (operatorsPriority.count(expr) > 0);
}

int OperatorsHandling::getOperatorPriority(std::string expr)
{
    return operatorsPriority.at(expr);
}

std::string ExpressionsHandling::toPrefix(const std::string &expression)
{
    std::stack<std::string> exprStack;
    std::string result = ""; // to store the resulting tokens

    // Pass the expression from the end to the beginning
    for (auto it = expression.rbegin(); it != expression.rend(); it++)
    {
        std::string op(1, *it); // Convert the character to string

        if (op == " " && !result.empty() && result.front() == ' ')
            continue;

        // Check if there is a "**" coefficient
        if (*it == '*' && (it + 1 != expression.rend() && *(it + 1) == '*'))
        {
            op = "**";
            it++; // Skip the second letter of "**"
        }

        bool isOperator = opHandling.isOperator(op); // Is op an operator or not
        if (!isOperator)
        {
            std::string nextChar(1, *(it + 1));
            if (*it != ' ' && it + 1 != expression.rend() && opHandling.isOperator(nextChar))
                result = " " + op + result;
            else
                result = op + result;
        }
        else if (!exprStack.empty() && exprStack.top() != ")" && op != ")")
        {
            // If the operator is present and has a special handling of braces or priorities
            if (op == "(")
            {
                // When facing "(" in the reverse traffic, we are looking for ")" in the stack
                while (!exprStack.empty() && exprStack.top() != ")")
                {
                    if (!result.empty() && result.front() != ' ')
                        result = " " + result;
                    result = exprStack.top() + result; // Add the operator with space to result
                    exprStack.pop();
                }
                if (!exprStack.empty())
                {
                    if (result.front() != ' ')
                        result = " " + result;
                    exprStack.pop(); // remove ")"
                }
            }
            else
            {
                // Compare the operators' priorities in the stack
                while (!exprStack.empty() && opHandling.getOperatorPriority(op) < opHandling.getOperatorPriority(exprStack.top()))
                {
                    if (!result.empty() && result.front() != ' ')
                        result = " " + result;
                    result = exprStack.top() + result;
                    exprStack.pop();
                }
                if (!result.empty() && result.front() != ' ')
                    result = " " + result;
                exprStack.push(op);
            }
        }
        else
        {
            exprStack.push(op);
        }
    }

    // Add what's left in the stack to the tokens
    while (!exprStack.empty())
    {
        if (!result.empty() && result.front() != ' ')
            result = " " + result;
        result = exprStack.top() + result;
        exprStack.pop();
    }

    if (result.back() == ' ')
        result.pop_back();

    return result;
}
