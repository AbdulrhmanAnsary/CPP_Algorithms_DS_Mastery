#include <iostream>
#include <algorithm>
#include "../workingWithArrays.h"

using namespace std;

void partition(int array[], int start, int end, int &left, int &right)
{
    left = start - 1;
    right = end;
    int pivotLeft = start - 1;
    int pivotRight = end;
    int pivotValue = array[end];

    while (true)
    {
        // We used two loops to find the elements that need swaps

        while (array[++left] < pivotValue)
            ; // Find the first element greater than pivot

        while (array[--right] > pivotValue) // Find the first element less than pivot
            if (right == start)
                break;

        if (left >= right)
            break;

        swap(array[left], array[right]);

        // Transfer the equal elements of the pivot to the left and right sides
        if (array[left] == pivotValue)
            swap(array[++pivotLeft], array[left]);
        if (array[right] == pivotValue)
            swap(array[right], array[--pivotRight]);
    }

    // Put the pivot in the right position
    swap(array[left], array[end]);

    // Transfer the equal elements of the pivot to thier right position
    right = left - 1;
    for (int i = start; i < pivotLeft; i++, right--)
    {
        swap(array[i], array[right]);
    }

    left = left + 1;
    for (int i = end - 1; i > pivotRight; i--, left++)
    {
        swap(array[left], array[i]);
    }
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int left, right;
        partition(array, start, end, left, right);

        quickSort(array, start, right); // Sorting the left side
        quickSort(array, left, end);    // Sorting the right side
    }
}

int main()
{
    int size = 100;
    int nums[size];
    WorkingWithArrays use;

    use.randomInsert(nums, size, true);
    use.printArray(nums, size);

    cout << "Is sorted: " << use.isSorted(nums, size) << endl;

    cout << "\nAfter quick sort:\n";
    quickSort(nums, 0, size - 1);
    use.printArray(nums, size);

    cout << "Is sorted: " << use.isSorted(nums, size) << endl;

    return 0;
}