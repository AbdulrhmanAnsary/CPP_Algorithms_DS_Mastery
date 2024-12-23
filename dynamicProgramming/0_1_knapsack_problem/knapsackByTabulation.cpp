// Here is the bottom-up approach of
// dynamic programming (Tabulation)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity
int knapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int itemsCount = weights.size();
    vector<vector<int>> k(itemsCount + 1, vector<int>(capacity + 1, 0));

    // Fill the k[][] table using dynamic programming
    for (int i = 1; i <= itemsCount; ++i)
    {
        for (int j = 0; j <= capacity; ++j)
        {
            if (i == 0 || j == 0)
                continue;
            else if (weights[i - 1] <= j)
                k[i][j] = max(values[i - 1] + k[i - 1][j - weights[i - 1]], k[i - 1][j]);
            else
                k[i][j] = k[i - 1][j];
        }
    }

    // The optimum value will be in k[itemsCount][capacity]
    return k[itemsCount][capacity];
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}