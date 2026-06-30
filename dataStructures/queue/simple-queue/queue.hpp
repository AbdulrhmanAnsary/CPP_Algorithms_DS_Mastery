// implementing queue using two stacks (inStack/outStack),
// inStack: to store new items during enqueue
// outStack: to store items that will be removed during DeQueue — after
// transferring them from inStack in reverse order (until FIFO).

#pragma once

#include <optional>
#include <stack>
#include <vector>

template <typename T>
class Queue
{
protected:
  std::stack<T> inStack, outStack;
  std::optional<T> front, rear;

public:
  Queue() = default;
  ~Queue() = default;

  bool empty() const;
  T getFront() const;
  T getRear() const;
  void enqueue(T item);
  void enqueue(const std::vector<T> &items);
  T dequeue();
};

// template definitions
#include "queue_impl.hpp"
