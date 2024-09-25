#include <iostream>
#include <cstdlib>
#include "../workingWithArrays.h"

using namespace std;

// Hoare's partitioning method with simplified loops
int division(int array[], int start, int end)
{
    int pivot = array[start];
    int i = start, j = end;

    while (true)
    {
        while (array[i] < pivot)
            i++;

        while (array[j] > pivot)
            j--;

        if (i >= j)
            return j;

        swap(array[i], array[j]);

        // Move pointers inside
        i++;
        j--;
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
    if (start < end)
    {
        int pivot = randomDivision(array, start, end);

        quickSort(array, start, pivot);
        quickSort(array, pivot + 1, end);
    }
}

int main(int argc, char *argv[])
{
    int size = 10;
    int nums[size];
    WorkingWithArrays use;

    use.randomInsert(nums, size, true);
    use.printArray(nums, size);

    cout << "After quick sort:\n";
    quickSort(nums, 0, size - 1);
    use.printArray(nums, size);

    return 0;
}
