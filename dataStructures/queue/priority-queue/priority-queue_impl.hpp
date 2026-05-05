#pragma once

#include "priority-queue.hpp"
#include <algorithm>

template <class T, class Container, class Compare>
void PriorityQueue<T, Container, Compare>::enqueue(const T &item) {
  container.push_back(item);
  std::push_heap(container.begin(), container.end(), compare);
}

template <class T, class Container, class Compare>
T PriorityQueue<T, Container, Compare>::dequeue() {}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getFront() const {}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getRear() const {}

template <class T, class Container, class Compare>
bool PriorityQueue<T, Container, Compare>::isEmpty() const {}

template <class T, class Container, class Compare>
size_t PriorityQueue<T, Container, Compare>::size() const {}
