#include <iostream>
#include <vector>
#include "../../data_structure_tools.h"

using namespace std;

vector<vector<int>> matricesMultiplied(const vector<vector<int>> &nums1, const vector<vector<int>> &nums2)
{
    int rows = nums1.size();
    int cols = nums2[0].size();
    int common_dim = nums2.size();

    // Initialized the result matrux
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < common_dim; k++)
                result[i][j] += nums1[i][k] * nums2[k][j];
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums1 = {{1, 2}, {3, 4}};
    vector<vector<int>> nums2 = {{5, 6}, {7, 8}};
    vector<vector<int>> result = matricesMultiplied(nums1, nums2);
    DataStructureTools tools;

    tools.printContainer(result);
    cout << endl;

    return 0;
}
