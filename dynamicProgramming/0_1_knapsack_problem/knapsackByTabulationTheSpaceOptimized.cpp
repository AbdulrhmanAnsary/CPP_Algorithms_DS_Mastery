// Here is the Space optimized Approach for
// 0/1 Knapsack Problem using Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm> // for std::max

using namespace std;

// Function to find the maximum profit
int knapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
    // Making and initializing k[] array
    vector<int> k(capacity + 1, 0);

    for (int i = 1; i <= weights.size(); i++)
    {
        // It is important to make sure that the values we use for weight do not come from the same current row.
        // So we calculate the values from right to left.
        // This prevents writing on values that have not yet been used in the current row.
        for (int j = capacity; j >= 0; j--)
        {
            if (weights[i - 1] <= j)
                // Finding the maximum value
                k[j] = max(k[j], k[j - weights[i - 1]] + values[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return k[capacity];
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