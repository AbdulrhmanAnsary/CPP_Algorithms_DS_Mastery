#include <iostream>
#include <algorithm>
#include "../data_structure_tools.h"

using namespace std;

void partition(int array[], int start, int end, int &left, int &right)
{
    int pivot = array[end];
    int current = start;
    left = start;
    right = end;

    while (current <= right)
    {
        if (array[current] < pivot)
            swap(array[left++], array[current++]);
        else if (array[current] > pivot)
            swap(array[current], array[right--]);
        else
            current++;
    }
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int left, right;
        partition(array, start, end, left, right);

        quickSort(array, start, left - 1);
        quickSort(array, right + 1, end);
    }
}

int main()
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