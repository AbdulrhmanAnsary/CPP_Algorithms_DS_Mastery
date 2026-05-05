#pragma once

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class IPriorityQueue {
protected:
  Container container;
  Compare compare;

public:
  using value_type = T;

  IPriorityQueue(Container container = Container(), Compare compare = Compare())
      : container(std::move(container)), compare(std::move(compare)) {}
  virtual ~IPriorityQueue() = default;

  // The API interface must be used by the user override
  virtual void enqueue(const T &item) = 0;
  virtual T dequeue() = 0;
  virtual const T &getFront() const = 0;
  virtual const T &getRear() const = 0;
  virtual bool isEmpty() const = 0;
  virtual size_t size() const = 0;
};

template <class T, class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class PriorityQueue : public IPriorityQueue<T, Container, Compare> {
public:
  using Base = IPriorityQueue<T, Container, Compare>;
  using Base::container;
  using Base::compare;

  void enqueue(const T &item) override;
  T dequeue() override;
  const T &getFront() const override;
  const T &getRear() const override;
  bool isEmpty() const override;
  size_t size() const override;
};

// Template definitions
#include "priority-queue_impl.hpp"
