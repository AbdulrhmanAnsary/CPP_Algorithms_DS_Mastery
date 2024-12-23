#include <iostream>
#include <vector>

using namespace std;

// The function restores the longest joint sub-seeration
int lcs(char *str1, char *str2, int len1, int len2)
{
    if (len1 == 0 || len2 == 0)
        return 0;
    if (str1[len1 - 1] == str2[len2 - 1])
        return 1 + lcs(str1, str2, len1 - 1, len2 - 1);
    else
        return max(lcs(str1, str2, len1, len2 - 1), lcs(str1, str2, len1 - 1, len2));
}

int main()
{
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    cout << "Length of LCS is " << lcs(str1, str2, len1, len2);

    return 0;
}
