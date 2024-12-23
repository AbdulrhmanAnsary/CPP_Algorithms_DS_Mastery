// Here is the top-down approach of
// dynamic programming (Memoization)

#include <iostream>
#include <vector>
#include <algorithm> // for std::max

using namespace std;

// Function to find the maximum profit with memoization (top-down approach)
int getMaxProfit(int capacity, const vector<int> &weights, const vector<int> &values, int currentIndex, vector<vector<int>> &memo)
{
    // Base case: if we reach an index before the first item, return 0
    if (currentIndex < 0)
        return 0;

    // If the value is already computed, return it from the memo table
    if (memo[currentIndex][capacity] != -1)
        return memo[currentIndex][capacity];

    // If the weight of the current item exceeds the remaining capacity, skip it
    if (weights[currentIndex] > capacity)
    {
        memo[currentIndex][capacity] = getMaxProfit(capacity, weights, values, currentIndex - 1, memo);
        return memo[currentIndex][capacity];
    }

    // Calculate the maximum profit by considering two cases:
    // 1. Including the current item
    // 2. Excluding the current item
    int includeItem = values[currentIndex] + getMaxProfit(capacity - weights[currentIndex], weights, values, currentIndex - 1, memo);
    int excludeItem = getMaxProfit(capacity, weights, values, currentIndex - 1, memo);

    // Store the maximum profit in memo table and return it
    memo[currentIndex][capacity] = max(includeItem, excludeItem);

    return memo[currentIndex][capacity];
}

// Wrapper function to initialize memo table and start the recursive function
int knapSack(int capacity, const vector<int> &weights, const vector<int> &values)
{
    int itemCount = values.size();

    // Initialize memo table with -1 for memoization
    vector<vector<int>> memo(itemCount, vector<int>(capacity + 1, -1));

    // Start the recursive function
    return getMaxProfit(capacity, weights, values, itemCount - 1, memo);
}

int main()
{
    vector<int> values = {60, 100, 120}; // Profits or values for each item
    vector<int> weights = {10, 20, 30};  // Weights for each item
    int capacity = 50;                   // Capacity of the knapsack

    cout << "Maximum profit: " << knapSack(capacity, weights, values) << endl;

    return 0;
}