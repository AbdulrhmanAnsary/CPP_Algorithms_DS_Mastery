#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getLCS(string str1, string str2)
{
    int lenStr1 = str1.length();
    int lenStr2 = str2.length();

    // Initialize the table to store the results
    vector<int> previousValues(lenStr2 + 1, 0);
    vector<int> currentValues(lenStr2 + 1, 0);

    for (int i = 1; i <= lenStr1; i++)
    {
        for (int j = 1; j <= lenStr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                currentValues[j] = previousValues[j - 1] + 1; // Use the previous row
            else
                currentValues[j] = max(currentValues[j - 1], previousValues[j]); // Compare with current and previous rows
        }
        // Switch the values of the previous row to the current row
        swap(previousValues, currentValues);
    }

    // Result is the last cell of the previous row (after swaping)
    return previousValues[lenStr2];
}

int main(int argc, char *argv[])
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int LCS = getLCS(str1, str2);

    cout << "The length of the LCS is: " << LCS << endl;

    return 0;
}