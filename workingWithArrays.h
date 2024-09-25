#ifndef WORKING_WITH_ARRAYS_H
#define WORKING_WITH_ARRAYS_H

#include <iostream>
#include <cstdlib>

class WorkingWithArrays
{
  public:
    void printArray(int array[], int size)
    {
        std::cout << "{";
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i];
            if (i < size - 1)
                std::cout << ", ";
        }
        std::cout << "}\n";
    }

    void randomInsert(int array[], int size, bool change = false)
    {
        if (change)
            srand(time(0));
        for (int i = 0; i < size; i++)
            array[i] = rand() % size;
    }

    bool isSorted(int array[], int size, bool upward_order = true)
    {
        for (int index = 0; index < size - 1; index++)
        {
            if (upward_order)
            {
                if (array[index] > array[index + 1])
                    return false;
            }
            else
            {
                if (array[index] < array[index + 1])
                    return false;
            }
        }
        return true;
    }
};
#endif