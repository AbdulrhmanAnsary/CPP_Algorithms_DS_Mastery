// C++ program to find the longest common subsequence of two strings
// using space optimization and single array

#include <iostream>
#include <vector>

using namespace std;

int getLCS(string &str1, string &str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // store the LCS values for the current row
    // dp[j] represents LCS of str1[0..i] and str2[0..j]
    vector<int> dp(lenStr2 + 1, 0);

    for (int i = 1; i <= lenStr1; ++i)
    {
        // prev stores the value from the previous
        // row and previous column (i-1), (j-1)
        int prev = dp[0];

        for (int j = 1; j <= lenStr2; ++j)
        {
            // temp temporarily stores the current dp[j]
            int temp = dp[j];

            // If characters match, add 1 to the value
            if (str1[i - 1] == str2[j - 1])
                dp[j] = 1 + prev;
            else
                // Otherwise, take the maximum of the left and top values
                dp[j] = max(dp[j - 1], dp[j]);

            // Update prev for the next iteration
            prev = temp;
        }
    }

    // The last element of the vector contains the length of the LCS
    return dp[lenStr2];
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int LCS = getLCS(str1, str2);

    cout << "The length of the LCS is: " << LCS << endl;

    return 0;
}