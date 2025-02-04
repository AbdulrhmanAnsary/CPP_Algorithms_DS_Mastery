#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

class ParenthesesBalance
{
  private:
    // Map to store matching pairs of parentheses
    map<char, char> parentheses = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};

  public:
    // Function to check if the parentheses in the string are balanced
    bool isBalanced(const string &brackets)
    {
        stack<char> bracketsStack; // Stack to keep track of open parentheses

        for (char bracket : brackets)
        {
            if (parentheses.count(bracket)) // If the character is an opening parenthesis
                bracketsStack.push(bracket);
            else if (!bracketsStack.empty() && parentheses[bracketsStack.top()] == bracket) // If it's a matching closing parenthesis
                bracketsStack.pop();                                                        // Remove the matching opening parenthesis from the stack
            else
                return false; // Case of unmatched or extra closing parenthesis
        }

        return bracketsStack.empty(); // If the stack is empty, the parentheses are balanced
    }
};

int main()
{
    ParenthesesBalance balance;

    // Store all test cases in a vector
    vector<string> tests = {
        "((([]){<(())()>}[))]",
        "((([]){<(())()>}[]))",
        "((([][]))()(()))",
        "((([][]))()(())",
        "((([][]))()(())))",
        "()[=!#]{}"};

    // Loop through each test case
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << ": ";
        if (balance.isBalanced(tests[i]))
            cout << "The brackets are Balanced!" << endl;
        else
            cout << "The brackets are NOT Balanced!" << endl;
    }

    return 0;
}