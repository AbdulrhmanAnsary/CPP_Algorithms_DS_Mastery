// Longest common subsequence by bottom-up approach (Tabulation) space optimized

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // Initialize the table to store the results
    vector<string> previousValues(lenStr2 + 1, "");
    vector<string> currentValues(lenStr2 + 1, "");

    for (int i = 1; i <= lenStr1; i++)
    {
        for (int j = 1; j <= lenStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                currentValues[j] = previousValues[j - 1] + str1[i - 1];
            else
                // Compare with current and previous rows
                currentValues[j] = (currentValues[j - 1].length() >= previousValues[j].length()) ? currentValues[j - 1] : previousValues[j];
        }
        // Switch the values of the previous row to the current row
        swap(previousValues, currentValues);
    }

    // Result is the last cell of the previous row (after swaping)
    return previousValues[lenStr2];
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
