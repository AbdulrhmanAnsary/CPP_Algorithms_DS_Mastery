#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int value;
    int weight;

    double valuePerWeight() const
    {
        return static_cast<double>(value) / weight;
    }
};

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.valuePerWeight() > b.valuePerWeight();
    });

    double totalValue = 0.0;

    for (const Item &item : items)
    {
        if (capacity == 0)
        {
            break;
        }

        if (item.weight <= capacity)
        {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else
        {
            totalValue += item.valuePerWeight() * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main()
{
    int capacity = 50;
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}};

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}