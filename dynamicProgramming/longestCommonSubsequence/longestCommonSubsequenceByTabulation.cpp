#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // Initialize the table to store the results
    vector<vector<int>> db(lenStr1 + 1, vector<int>(lenStr2 + 1, 0));

    for (int i = 1; i <= lenStr1; i++)
    {
        for (int j = 1; j <= lenStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                db[i][j] = db[i - 1][j - 1] + 1;
            else
                db[i][j] = max(db[i - 1][j], db[i][j - 1]);
        }
    }

    return db[lenStr1][lenStr2];
}

int main(int argc, char *argv[])
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int LCS = getLCS(str1, str2);

    cout << "The length of the LCS is: " << LCS << endl;

    return 0;
}