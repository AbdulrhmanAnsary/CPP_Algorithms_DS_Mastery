#pragma once

#include "queue.hpp"
#include <stdexcept>

template <typename T> bool Queue<T>::empty() const {
  return inStack.empty() && outStack.empty();
}

template <typename T> void Queue<T>::enqueue(T item) {
  if (inStack.empty()) {
    front = item;
  }

  rear = item;
  inStack.push(item);
}

template <typename T> void Queue<T>::enqueue(const std::vector<T> &items) {
  if (inStack.empty()) {
    front = items.front();
  }

  for (auto item : items) {
    rear = item;
    inStack.push(item);
  }
}

template <typename T> T Queue<T>::dequeue() {
  if (empty()) {
    throw std::underflow_error("Cannot dequeue from empty queue");
  }

  if (outStack.empty()) {
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

  T result = outStack.top();
  outStack.pop();

  if (!outStack.empty()) {
    front = outStack.top();
  } else {
    front.reset();
    rear.reset();
  }

  return result;
}

template <typename T> T Queue<T>::getFront() const {
  if (!front.has_value()) {
    throw std::runtime_error("Queue is empty - getFront not available");
  }
  return *front;
}

template <typename T> T Queue<T>::getRear() const {
  if (!rear.has_value()) {
    throw std::runtime_error("Queue is empty - getRear not available");
  }

  return *rear;
}
