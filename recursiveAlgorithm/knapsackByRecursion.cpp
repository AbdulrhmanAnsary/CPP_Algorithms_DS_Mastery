/* A Naive recursive implementation of
 0-1 Knapsack problem */

#include <iostream>
#include <algorithm> // for std::max

using namespace std;

// Function to calculate the maximum value that can be obtained within a given knapsack capacity
int knapSack(int capacity, const int weights[], const int values[], int itemCount)
{
    // Base case: If the knapsack has no capacity or there are no items left
    if (itemCount == 0 || capacity == 0)
        return 0;

    // If the weight of the last item is more than the capacity, it cannot be included
    if (weights[itemCount - 1] > capacity)
        return knapSack(capacity, weights, values, itemCount - 1);

    // Calculate the maximum value by considering two cases:
    // 1. Including the last item
    // 2. Not including the last item
    int includeItem = values[itemCount - 1] + knapSack(capacity - weights[itemCount - 1], weights, values, itemCount - 1);
    int excludeItem = knapSack(capacity, weights, values, itemCount - 1);

    return max(includeItem, excludeItem);
}

int main()
{
    const int values[] = {60, 100, 120};                      // Profits or values for each item
    const int weights[] = {10, 20, 30};                       // Weights for each item
    const int capacity = 50;                                  // Capacity of the knapsack
    const int itemCount = sizeof(values) / sizeof(values[0]); // Number of items

    cout << "Maximum value that can be obtained: " << knapSack(capacity, weights, values, itemCount) << endl;

    return 0;
}