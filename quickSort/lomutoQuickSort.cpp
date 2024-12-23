#include <cstdlib>
#include <iostream>
#include "../data_structure_tools.h"

using namespace std;

// Lomuto's partitioning method

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int index = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
            // We make a preincrement for 'index'
            swap(array[++index], array[j]);
    }

    swap(array[index + 1], array[end]);

    return (index + 1);
}

int partition_r(int array[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start + 1);

    swap(array[random], array[end]);

    return partition(array, start, end);
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition_r(array, start, end);

        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int main()
{
    int size = 10;
    int nums[size];
    DataStructureTools tools;

    tools.randomFill(nums, size);
    tools.printContainer(nums, size);

    cout << "After quick sort:\n";
    quickSort(nums, 0, size - 1);
    tools.printContainer(nums, size);

    return 0;
}