#pragma once

#include <cstddef>
#include <optional>

template <typename T> class CircularQueue {
private:
  class Node {
  public:
    T value;
    Node *next = nullptr;

  public:
    Node() = default;
    Node(const T &val) : value(val) {}
    ~Node() = default;
  };

protected:
  Node *front = nullptr;
  Node *rear = nullptr;
  size_t nodesNum = 0;

public:
  CircularQueue() = default;
  ~CircularQueue() {
    if (!isEmpty()) {
      dequeue();
    }
  };

  bool isEmpty();
  size_t size();
  std::optional<T> getFront();
  std::optional<T> getRear();
  void enqueue(T item);
  std::optional<T> dequeue();
};

// Template definitions
#include "circular-queue_impl.hpp"
