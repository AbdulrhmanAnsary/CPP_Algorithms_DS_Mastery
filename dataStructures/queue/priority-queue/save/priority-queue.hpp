#pragma once

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class PriorityQueue {
private:
  Container container;
  Compare compare;

public:
  PriorityQueue(Container container = Container(), Compare compare = Compare()) : container(std::move(container)), compare(std::move(compare)) {}
  ~PriorityQueue() = default;

  void enqueue(T item);
  const T &dequeue() const;
  const T &getFront() const;
  const T &getRear() const;
  bool isEmpty() const;
  size_t size() const;
};

// Template definitions
#include "priority-queue_impl.hpp"
