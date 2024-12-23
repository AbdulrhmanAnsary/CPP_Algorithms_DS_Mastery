// Author: Abdulrhman Ansary
// Modification date: 5 November 2024

#ifndef DATA_STRUCTURE_TOOLS_H
#define DATA_STRUCTURE_TOOLS_H

#include <iostream>
#include <cstdlib>
#include <vector>

class DataStructureTools
{
  public:
    template <typename Container>
    void printContainer(Container &container)
    {
        if constexpr (std::is_arithmetic_v<Container>)
        {
            // Print basic types (e.g., int, float)
            std::cout << container;
        }
        else if constexpr (std::is_same_v<Container, std::string>)
        {
            // Print std::string directly
            std::cout << container;
        }
        else if constexpr (std::is_array_v<Container>)
        {
            // Print raw arrays
            std::cout << "{";
            size_t size = std::extent_v<Container>;
            for (size_t i = 0; i < size; i++)
            {
                printContainer(container[i]);
                if (i < size - 1)
                    std::cout << ", ";
            }
            std::cout << "}";
        }
        else if constexpr (std::is_class_v<Container> && std::is_same_v<decltype(container.begin()), decltype(container.end())>)
        {
            // Print containers (e.g., std::vector)
            std::cout << "{";
            for (auto item = container.begin(); item != container.end(); ++item)
            {
                printContainer(*item);
                if (next(item) != container.end())
                    std::cout << ", ";
            }
            std::cout << "}";
        }
        else
        {
            // Fallback for unsupported types
            std::cout << "[Unsupported type]";
        }
    }

    // Randomly insert elements into a C-style array
    void randomFill(int array[], int size, bool changeSeed = false)
    {
        if (changeSeed)
            srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < size; i++)
            array[i] = rand() % size;
    }

    // Randomly insert elements into any STL container
    template <typename Container>
    void randomFill(Container &container, int size, bool changeSeed = false)
    {
        if (container.size() < size)
            container.resize(size);
        if (changeSeed)
            srand(static_cast<unsigned int>(time(0)));
        std::generate(container.begin(), container.end(), [size]() {
            return rand() % size;
        });
    }

    // Check if a C-style array is sorted
    bool isSorted(int arry[], int size, bool ascending = true)
    {
        return std::is_sorted(arry, arry + size, [ascending](int a, int b) {
            return ascending ? a <= b : a >= b;
        });
    }

    // Generic function check if any STL container is sorted (vector, list, deque, array, etc.)
    template <typename Container>
    bool isSorted(const Container &container, bool ascending = true)
    {
        return is_sorted(container.begin(), container.end(), [ascending](int a, int b) {
            return ascending ? a <= b : a >= b;
        });
    }
};
#endif