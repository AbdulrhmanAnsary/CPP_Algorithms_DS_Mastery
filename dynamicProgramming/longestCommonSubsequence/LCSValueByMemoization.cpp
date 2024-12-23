// Longest common subsequence by top-down approach (memoization)

#include <iostream>
#include <vector>

using namespace std;

// An auxiliary function to find the LCS
string findLCS(string str1, string str2, int lenStr1, int lenStr2, vector<vector<string>> &memo)
{
    // Base case: if one string is empty
    if (lenStr1 == 0 || lenStr2 == 0)
        return "";

    // If the value is already computed, return it from the memo table
    if (memo[lenStr1][lenStr2] != "?")
        return memo[lenStr1][lenStr2];

    // If the last characters are equal
    if (str1[lenStr1 - 1] == str2[lenStr2 - 1])
        return memo[lenStr1][lenStr2] = findLCS(str1, str2, lenStr1 - 1, lenStr2 - 1, memo) + str1[lenStr1 - 1];

    // If the last characters are not equal
    string excludeLast1 = findLCS(str1, str2, lenStr1 - 1, lenStr2, memo);
    string excludeLast2 = findLCS(str1, str2, lenStr1, lenStr2 - 1, memo);
    return memo[lenStr1][lenStr2] = (excludeLast1.length() >= excludeLast2.length() ? excludeLast1 : excludeLast2);
}

string getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // Initialize the table to store the results
    vector<vector<string>> memo(lenStr1 + 1, vector<string>(lenStr2 + 1, "?"));

    return findLCS(str1, str2, lenStr1, lenStr2, memo);
}

int main(int argc, char *argv[])
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    string LCS = getLCS(str1, str2);

    cout << "The LCS is: " << LCS << endl;
    cout << "The length of the LCS is: " << LCS.length() << endl;

    return 0;
}
