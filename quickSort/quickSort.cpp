#include <iostream>
#include "../data_structure_tools.h"

using namespace std;

int division(int array[], int start, int end)
{
    int pivot = array[end];
    int index = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] < pivot)
            swap(array[index++], array[i]);
    }

    // We toolsd array[end] instead of pivot becuase the pivot has the value not the address
    swap(array[index], array[end]);

    return index;
}

int randomDivision(int array[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start + 1);

    swap(array[random], array[end]);

    return division(array, start, end);
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = randomDivision(array, start, end);

        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int main(int argc, char *argv[])
{
    int size = 10;
    int nums[size];
    DataStructureTools tools;

    tools.randomFill(nums, size, true);
    tools.printContainer(nums, size);

    cout << "After quick sort:\n";
    quickSort(nums, 0, size - 1);
    tools.printContainer(nums, size);

    return 0;
}