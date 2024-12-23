#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> minCoins(vector<int> &coins, int remainder)
{
    // Sort the coins in decreasing order.
    sort(coins.rbegin(), coins.rend());

    // Initialize result
    vector<int> result;

    // Traverse through all denomination
    for (auto coin = coins.begin(); remainder > 0 && coin != coins.end(); coin++)
    {
        int coinsCount = remainder / *coin; // Calculate how many of this coin can be used
        remainder %= *coin;                 // Update the remainder

        // Add the coin 'count' times to the result
        result.insert(result.end(), coinsCount, *coin);
    }

    return result;
}

void printVector(const vector<int> &container)
{
    for (const auto &item : container)
        cout << item << " ";
    cout << endl;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int remainder = 93;

    vector<int> result = minCoins(coins, remainder);

    cout << "Minimum number of coins required: " << result.size() << endl;
    printVector(result);

    return 0;
}