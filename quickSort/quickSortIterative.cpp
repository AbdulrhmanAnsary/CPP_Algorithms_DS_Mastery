#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include "../data_structure_tools.h"

using namespace std;

int division(int array[], int start, int end)
{
    int pivot = array[start];
    int i = start - 1;
    int j = end + 1;

    while (true)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array[i], array[j]);
    }
}

int randomDivision(int array[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start + 1);

    swap(array[random], array[start]);

    return division(array, start, end);
}

void quickSort(int array[], int start, int end)
{
    stack<int> stack;

    stack.push(start);
    stack.push(end);

    while (!stack.empty())
    {
        end = stack.top();
        stack.pop();

        start = stack.top();
        stack.pop();

        int pivot = randomDivision(array, start, end);

        // Find if the left side has any elements
        if (pivot > start)
        {
            stack.push(start);
            stack.push(pivot);
        }

        // Find if the right side has any element
        if (pivot + 1 < end)
        {
            stack.push(pivot + 1);
            stack.push(end);
        }
    }
}

int main(int argc, char *argv[])
{
    int size = 100;
    int nums[size];
    DataStructureTools tools;

    tools.randomFill(nums, size, true);
    tools.printContainer(nums, size);

    cout << "Is sorted: " << tools.isSorted(nums, size) << endl;

    cout << "\nAfter quick sort:\n";
    quickSort(nums, 0, size - 1);
    tools.printContainer(nums, size);

    cout << "Is sorted: " << tools.isSorted(nums, size) << endl;

    return 0;
}