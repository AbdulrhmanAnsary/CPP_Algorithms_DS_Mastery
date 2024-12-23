//Top-down approach (Memoization) for printing Longest Common Subsequence

#include <iostream>
#include <map>
#include <string>

using namespace std;

//names abbreviations
using StringPair = pair<string, string>;
using StringMap = map<StringPair, string>;
using VisitMap = map<StringPair, int>;

// General variables to store results and track visits
StringMap memoizationTable;
VisitMap visited;

// reverse texts
string reverseString(const string &str)
{
    string reversed = str;
    int left = 0;
    int right = reversed.length() - 1;

    while (left < right)
        swap(reversed[left++], reversed[right--]);

    return reversed;
}

// Compare texts and return the longest
string getLongerString(const string &str1, const string &str2)
{
    return (str1.length() > str2.length()) ? str1 : str2;
}

// the basic function of calculating the longest common subsequence
string computeLCS(const string &str1, const string &str2)
{
    // Base case
    if (str1.empty() || str2.empty())
        return "";

    StringPair state = {str1, str2};

    // if the case has already been visited
    if (visited[state])
        return memoizationTable[state];

    // Determine the status as it has been visited
    visited[state] = 1;

    // If the last text characters are identical
    if (str1.back() == str2.back())
    {
        string result = computeLCS(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1));
        result += str1.back();
        memoizationTable[state] = result;

        return result;
    }

    // If they are not identical, choose the longest between the two cases
    string result = getLongerString(
        computeLCS(str1.substr(0, str1.length() - 1), str2),
        computeLCS(str1, str2.substr(0, str2.length() - 1)));
    memoizationTable[state] = result;

    return result;
}

string findLCS(const string &str1, const string &str2)
{
    string lcs = computeLCS(str1, str2);

    return reverseString(lcs);
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    cout << "Longest Common Subsequence: " << findLCS(str1, str2) << endl;

    return 0;
}