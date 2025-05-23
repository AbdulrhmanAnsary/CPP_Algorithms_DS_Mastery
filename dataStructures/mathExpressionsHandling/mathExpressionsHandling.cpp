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
                    // if (result.front() != ' ') // This check might be redundant or misplaced for prefix logic here.
                    //    result = " " + result; // Spacing should be handled when adding to result.
                    exprStack.pop(); // remove ")" (original '(')
                }
                else // Mismatched parenthesis: op == "(" (original ')') without matching ")" (original '(') on stack
                {
                    return "Error: Mismatched parentheses.";
                }
            }
            else
            {
                // Compare the operators' priorities in the stack
                // Adjusted condition for right-associativity of "**"
                while (!exprStack.empty() && exprStack.top() != ")" &&
                       ( (op == "**" && opHandling.getOperatorPriority(op) <= opHandling.getOperatorPriority(exprStack.top())) ||
                         (op != "**" && opHandling.getOperatorPriority(op) < opHandling.getOperatorPriority(exprStack.top())) ))
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
        if (exprStack.top() == ")") { // Mismatched parenthesis (original '(' was not closed by a ')')
            return "Error: Mismatched parentheses.";
        }
        if (!result.empty() && result.front() != ' ')
            result = " " + result;
        result = exprStack.top() + result;
        exprStack.pop();
    }

    // Corrected final space removal for potential leading space
    if (!result.empty() && result.front() == ' ')
        result.erase(0, 1);

    return result;
}

std::string ExpressionsHandling::toPostfix(const std::string &expression)
{
    std::stack<std::string> operatorStack;
    std::string result = "";
    std::string currentNumber = "";

    for (int i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];
        std::string token(1, c);

        if (std::isspace(c)) // Skip spaces
        {
            continue;
        }
        else if (std::isdigit(c)) // Token is a number
        {
            currentNumber += token;
            // Continue to gather all digits of the number
            while (i + 1 < expression.length() && std::isdigit(expression[i + 1]))
            {
                currentNumber += expression[++i];
            }
            if (!result.empty() && result.back() != ' ')
            {
                result += " ";
            }
            result += currentNumber;
            currentNumber = ""; // Reset for next number
        }
        else if (c == '(')
        {
            operatorStack.push(token);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != "(")
            {
                if (!result.empty() && result.back() != ' ')
                {
                    result += " ";
                }
                result += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty()) // Pop the '('
            {
                operatorStack.pop();
            }
            else // Mismatched parenthesis: ')' without matching '('
            {
                return "Error: Mismatched parentheses.";
            }
        }
        else // Token is an operator
        {
            std::string op_token_str(1, c);
            // Check for "**" operator
            if (c == '*' && i + 1 < expression.length() && expression[i + 1] == '*')
            {
                op_token_str = "**";
                i++; // Move past the second '*'
            }
            
            // Ensure the operator is valid before proceeding
            if (!opHandling.isOperator(op_token_str)) {
                // Handle invalid token, e.g., by throwing an error or skipping
                // For now, let's assume valid inputs or skip invalid tokens
                continue;
            }

            // Special handling for right-associative operators like exponentiation (**)
            // For left-associative, use: opHandling.getOperatorPriority(op_token_str) <= opHandling.getOperatorPriority(operatorStack.top())
            // For right-associative (like '**'), use: opHandling.getOperatorPriority(op_token_str) < opHandling.getOperatorPriority(operatorStack.top())
            // However, the current problem description implies standard left-associativity for typical operators,
            // and the provided priority map doesn't distinguish associativity for "**".
            // We will stick to "<=" for now, which is standard for left-associative.
            // If "**" should be right-associative, this condition needs adjustment for it.
            while (!operatorStack.empty() && operatorStack.top() != "(" &&
                   opHandling.getOperatorPriority(op_token_str) <= opHandling.getOperatorPriority(operatorStack.top()))
            {
                if (!result.empty() && result.back() != ' ')
                {
                    result += " ";
                }
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(op_token_str);
        }
    }

    // Append any remaining number
    if (!currentNumber.empty())
    {
        if (!result.empty() && result.back() != ' ')
        {
            result += " ";
        }
        result += currentNumber;
    }

    // Pop remaining operators from the stack
    while (!operatorStack.empty())
    {
        if (operatorStack.top() == "(") { // Mismatched parenthesis: '(' on stack without matching ')'
             return "Error: Mismatched parentheses.";
        }
        if (!result.empty() && result.back() != ' ')
        {
            result += " ";
        }
        result += operatorStack.top();
        operatorStack.pop();
    }

    // Remove leading/trailing spaces (final cleanup)
    size_t first = result.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return ""; // Result is empty or all spaces
    }
    size_t last = result.find_last_not_of(' ');
    return result.substr(first, (last - first + 1));
}

std::string ExpressionsHandling::toInfix(const std::string &expression)
{
    // TODO: Implement proper conversion logic if this method is intended for prefix/postfix to infix.
    // For now, it's a stub as per the plan.
    // The parameter 'expression' is unused in this stub.
    (void)expression; // Mark as intentionally unused to avoid compiler warnings.
    return "Error: Conversion to infix not implemented yet.";
}

int ExpressionsHandling::clacPrefix(const std::string &expression)
{
    (void)expression; // Mark as unused for now
    // TODO: Implement prefix expression evaluation
    return 0; // Placeholder return
}

int ExpressionsHandling::clacInfix(const std::string &expression)
{
    (void)expression; // Mark as unused for now
    // TODO: Implement infix expression evaluation (perhaps by converting to postfix and evaluating)
    return 0; // Placeholder return
}

int ExpressionsHandling::clacPostfix(const std::string &expression)
{
    (void)expression; // Mark as unused for now
    // TODO: Implement postfix expression evaluation
    return 0; // Placeholder return
}
