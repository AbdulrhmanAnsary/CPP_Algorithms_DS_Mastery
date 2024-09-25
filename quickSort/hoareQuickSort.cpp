#include <iostream>
#include <cstdlib>
#include "../workingWithArrays.h"

using namespace std;

// Hoare's partitioning method

int partition(int array[], int start, int end)
{
    int pivot = array[start]; // Choose the pivot as the first element
    int i = start - 1;        // Initialize the left pointer
    int j = end + 1;          // Initialize the right pointer

    while (true)
    {
        // Move the left pointer to the right until finding a value >= pivot
        do
        {
            i++;
        } while (array[i] < pivot);

        // Move the right pointer to the left until finding a value <= pivot
        do
        {
            j--;
        } while (array[j] > pivot);

        // If pointers cross, return the partition index
        if (i >= j)
            return j;

        // Swap the elements at i and j to put them in the correct partition
        swap(array[i], array[j]);
    }
}

int partition_r(int array[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start + 1);

    swap(array[random], array[start]);

    return partition(array, start, end);
}

// QuickSort using Hoare's partitioning method
void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        // Perform the partition
        int pivot = partition_r(array, start, end);

        // Recursively apply quickSort to the left and right partitions
        quickSort(array, start, pivot);
        quickSort(array, pivot + 1, end);
    }
}

int main()
{
    int size = 10;
    int nums[size];
    WorkingWithArrays use;

    use.randomInsert(nums, size);
    use.printArray(nums, size);

    cout << "After quick sort:\n";
    quickSort(nums, 0, size - 1);
    use.printArray(nums, size);

    return 0;
}
