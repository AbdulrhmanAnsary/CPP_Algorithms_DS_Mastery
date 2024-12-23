#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, string> getLCS(const string &str1, const string &str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    vector<vector<int>> dp(lenStr1 + 1, vector<int>(lenStr2 + 1, 0));

    for (int i = 1; i <= lenStr1; i++)
    {
        for (int j = 1; j <= lenStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // // LCS Reconstruction
    string lcs = "";
    int i = lenStr1, j = lenStr2;

    // Traverse the 2D array starting from dp[lenSte1][lenStr2]. Do following for every cell dp[i][j]
    while (i > 0 && j > 0)
    {
        // If characters (in str1 and str2) corresponding to dp[i][j] are same (Or str1[i-1] == str2[j-1]),
        // then include this character as part of lcs. 
        if (str1[i - 1] == str2[j - 1])
        {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        }
        // Else compare values of dp[i-1][j] and dp[i][j-1] and go in direction of greater value.
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return {dp[lenStr1][lenStr2], lcs};
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    auto [LCSLength, LCSString] = getLCS(str1, str2);

    cout << "The length of the LCS is: " << LCSLength << endl;
    cout << "The LCS is: " << LCSString << endl;

    return 0;
}