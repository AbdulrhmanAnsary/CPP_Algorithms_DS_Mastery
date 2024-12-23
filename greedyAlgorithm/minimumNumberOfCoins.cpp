#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minCoins(vector<int> &coins, int total)
{
    // Currency arrangement in descending order.
    sort(coins.rbegin(), coins.rend());

    int coinsCount = 0;

    for (auto coin = coins.begin(); total > 0 && coin != coins.end(); coin++)
    {
        coinsCount += (total / *coin); // Calculate how many of this coin can be used
        total %= *coin;              // Update the remainder
    }

    return coinsCount;
}

int main(int argc, char *argv[])
{
    vector<int> coins = {10, 25, 1, 5, 100, 50};
    int remainder = 173;

    int result = minCoins(coins, remainder);

    cout << "Minimum number of coins required: " << result << endl;

    return 0;
}