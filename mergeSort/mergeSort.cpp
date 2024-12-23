#include <iostream>
#include <cstdlib>
#include "../data_structure_tools.h"

using namespace std;

void merge(int array[], int start, int middle, int end)
{
    int temp[end - start + 1];
    int i = start, j = middle + 1, k = 0;

    // Sort arrays
    while (i <= middle && j <= end)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    // Add the remains from the first array
    while (i <= middle)
        temp[k++] = array[i++];

    // Add the remains from the second array
    while (j <= end)
        temp[k++] = array[j++];

    // Merge the arrays
    for (int i = start; i <= end; i++)
        array[i] = temp[i - start];
}

void mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        // Divide the array
        int middle = (start + end) / 2;

        // Recursive sort on both halves
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);

        // Merge the sorted halves
        merge(array, start, middle, end);
    }
}

int main(int argc, char *argv[])
{
    int size = 100;
    int nums[size];
    DataStructureTools tools;

    tools.randomFill(nums, size);
    tools.printContainer(nums, size);

    cout << "After merge sort:\n";
    mergeSort(nums, 0, size - 1);
    tools.printContainer(nums, size);

    return 0;
}
