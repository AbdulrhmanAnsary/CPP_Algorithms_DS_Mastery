// Longest common subsequence by bottom-up approach (Tabulation)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    vector<vector<string>> lcsTable(lenStr1 + 1, vector<string>(lenStr2 + 1, ""));

    for (int i = 1; i <= lenStr1; i++)
    {
        for (int j = 1; j <= lenStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + str1[i - 1];
            else
                lcsTable[i][j] = (lcsTable[i - 1][j].length() >= lcsTable[i][j - 1].length()) ? lcsTable[i - 1][j] : lcsTable[i][j - 1];
        }
    }

    return lcsTable[lenStr1][lenStr2];
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    string LCS = getLCS(str1, str2);

    cout << "The LCS is: " << LCS << endl;
    cout << "The length of the LCS is: " << LCS.length() << endl;

    return 0;
}
