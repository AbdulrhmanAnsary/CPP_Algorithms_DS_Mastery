#include <iostream>
#include <vector>

using namespace std;

// An auxiliary function to find the LCS
int findLCS(string str1, string str2, int lenStr1, int lenStr2, vector<vector<int>> &memo)
{
    // Base case: if one string is empty
    if (lenStr1 == 0 || lenStr2 == 0)
        return 0;

    // If the value is already computed, return it from the memo table
    if (memo[lenStr1][lenStr2] != -1)
        return memo[lenStr1][lenStr2];

    // If the last characters are equal
    if (str1[lenStr1 - 1] == str2[lenStr2 - 1])
        return memo[lenStr1][lenStr2] = findLCS(str1, str2, lenStr1 - 1, lenStr2 - 1, memo) + 1;

    // If the last characters are not equal
    int excludeLast1 = findLCS(str1, str2, lenStr1 - 1, lenStr2, memo);
    int excludeLast2 = findLCS(str1, str2, lenStr1, lenStr2 - 1, memo);
    return memo[lenStr1][lenStr2] = max(excludeLast1, excludeLast2);
}

int getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // Initialize the table to store the results
    vector<vector<int>> memo(lenStr1 + 1, vector<int>(lenStr2 + 1, -1));

    return findLCS(str1, str2, lenStr1, lenStr2, memo);
}

int main(int argc, char *argv[])
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int LCS = getLCS(str1, str2);

    cout << "The of the LCS is: " << LCS << endl;

    return 0;
}