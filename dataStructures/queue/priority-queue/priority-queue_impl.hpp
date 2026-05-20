#pragma once

#include "priority-queue.hpp"
#include <algorithm>

template <class T, class Container, class Compare>
void PriorityQueue<T, Container, Compare>::enqueue(const T &item)
{
    container.push_back(item);
    std::push_heap(container.begin(), container.end(), compare);
}

template <class T, class Container, class Compare>
T PriorityQueue<T, Container, Compare>::dequeue()
{
    std::pop_heap(container.begin(), container.end(), compare);
    T item = container.back();
    container.pop_back();
    return item;
}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getFront() const
{
    return container.front();
}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getRear() const
{
    return container.back();
}

template <class T, class Container, class Compare>
bool PriorityQueue<T, Container, Compare>::isEmpty() const
{
    return container.empty();
}

template <class T, class Container, class Compare>
size_t PriorityQueue<T, Container, Compare>::size() const
{
    return container.size();
}
