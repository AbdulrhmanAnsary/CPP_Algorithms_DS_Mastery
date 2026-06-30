#pragma once

#include "circular-queue.hpp"

template <typename T> void CircularQueue<T>::enqueue(T item) {
  Node *newNode = new Node(item);

  if (front == nullptr) {
    front = rear = newNode;
    rear->next = front; // circular
  } else {
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
  }

  nodesNum++;
}

template <typename T> std::optional<T> CircularQueue<T>::dequeue() {
  if (isEmpty()) {
    return std::nullopt;
  }

  Node *firstNode = front;
  T value = firstNode->value;

  if (front == rear) {
    front = rear = nullptr;
  } else {
    front = front->next;
    rear->next = front;
  }

  delete firstNode;
  nodesNum--;

  return value;
}

template <typename T> bool CircularQueue<T>::isEmpty() { return nodesNum == 0; }

template <typename T> size_t CircularQueue<T>::size() { return nodesNum; }

template <typename T> std::optional<T> CircularQueue<T>::getFront() {
  if (isEmpty()) {
    return std::nullopt;
  }

  return front->value;
}

template <typename T> std::optional<T> CircularQueue<T>::getRear() {
  if (isEmpty()) {
    return std::nullopt;
  }

  return rear->value;
}
