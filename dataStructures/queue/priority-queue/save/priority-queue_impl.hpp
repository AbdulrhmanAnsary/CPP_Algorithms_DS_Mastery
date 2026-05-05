#pragma once

#include "priority-queue.hpp"

template <class T, class Container, class Compare>
void PriorityQueue<T, Container, Compare>::enqueue(T item) {}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::dequeue() const {}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getFront() const {}

template <class T, class Container, class Compare>
const T &PriorityQueue<T, Container, Compare>::getRear() const {}

template <class T, class Container, class Compare>
bool PriorityQueue<T, Container, Compare>::isEmpty() const {}

template <class T, class Container, class Compare>
size_t PriorityQueue<T, Container, Compare>::size() const {}
