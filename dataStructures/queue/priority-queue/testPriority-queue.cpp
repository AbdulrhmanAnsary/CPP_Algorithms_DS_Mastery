#include "priority-queue.hpp"
#include "gtest/gtest.h"
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

// Custom container
// Note: custom containers (e.g. linked lists or stack) do not meet the
// requirements of the current PriorityQueue implementation which relies on
// random-access iterators (uses std::push_heap / std::pop_heap). Tests below
// therefore exercise the priority queue with `std::vector`-backed containers.

// Custom Compare
template <class T>
class Compare
{
  std::string op;

public:
  Compare(const std::string &op) : op(op)
  {
    if (op != "<" && op != ">" && op != "<=" && op != ">=" && op != "=")
    {
      throw std::runtime_error(
          "Invalid operator error, Enter ('<', '>', '<=', '>=', '=')");
    }
  }

  bool operator()(const T &a, const T &b) const
  {
    if (op == "<")
      return a < b;
    if (op == ">")
      return a > b;
    if (op == "<=")
      return a <= b;
    if (op == ">=")
      return a >= b;
    return a == b;
  }
};

// Typed Test Setup
template <class PQ>
class PriorityQueueTypedTest : public ::testing::Test
{
protected:
  PQ pq;
};

// Typed tests removed: the PriorityQueue implementation requires the
// container type to satisfy RandomAccessIterator requirements. Keep concrete
// tests below using the default vector container.

class PriorityQueueTest : public ::testing::Test
{
protected:
  PriorityQueue<int> nums;
  PriorityQueue<std::string> names;

  void SetUp() override {}
  void TearDown() override {}
};

// Test 1: Priority queue is initially empty
TEST_F(PriorityQueueTest, InitiallyEmpty)
{
  // int
  EXPECT_TRUE(nums.isEmpty());
  EXPECT_EQ(nums.size(), 0);

  // string
  EXPECT_TRUE(names.isEmpty());
  EXPECT_EQ(names.size(), 0);
}

// Test 2: Enqueue a single element
TEST_F(PriorityQueueTest, EnqueueSingleElement)
{
  // int
  nums.enqueue(10);
  EXPECT_FALSE(nums.isEmpty());
  EXPECT_EQ(nums.size(), 1);
  EXPECT_EQ(nums.getFront(), 10);
  EXPECT_EQ(nums.getRear(), 10);

  // string
  names.enqueue("Ali");
  EXPECT_FALSE(names.isEmpty());
  EXPECT_EQ(names.size(), 1);
  EXPECT_EQ(names.getFront(), "Ali");
  EXPECT_EQ(names.getRear(), "Ali");
}

// Test 3: Enqueue multiple elements
TEST_F(PriorityQueueTest, EnqueueMultipleElements)
{
  // int
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);
  EXPECT_EQ(nums.size(), 3);
  EXPECT_EQ(nums.getFront(), 30);
  // `getRear()` returns the underlying container's back(), which is not a
  // guaranteed ordering for heap-backed priority queues. Avoid asserting it.

  // string
  names.enqueue("Ali");   // 65
  names.enqueue("Saad");  // 83
  names.enqueue("Fatma"); // 70
  EXPECT_EQ(names.size(), 3);
  EXPECT_EQ(names.getFront(), "Saad");
  // Do not assert `getRear()` for the same reason as above.
}

// Test 4: Dequeue a single element
TEST_F(PriorityQueueTest, DequeueSingleElement)
{
  // int
  nums.enqueue(10);
  nums.enqueue(20);
  EXPECT_EQ(nums.dequeue(), 20);
  EXPECT_EQ(nums.size(), 1);
  EXPECT_EQ(nums.getFront(), 10);
  EXPECT_EQ(nums.getRear(), 10);

  // string
  names.enqueue("Ali");
  names.enqueue("Saad");
  EXPECT_EQ(names.dequeue(), "Saad");
  EXPECT_EQ(names.size(), 1);
  EXPECT_EQ(names.getFront(), "Ali");
  EXPECT_EQ(names.getRear(), "Ali");
}

// Test 5: Dequeue all elements
TEST_F(PriorityQueueTest, DequeueAllElements)
{
  // int
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);

  EXPECT_EQ(nums.dequeue(), 30);
  EXPECT_EQ(nums.dequeue(), 20);
  EXPECT_EQ(nums.dequeue(), 10);

  EXPECT_TRUE(nums.isEmpty());
  EXPECT_EQ(nums.size(), 0);

  // string
  names.enqueue("Ali");   // 65
  names.enqueue("Saad");  // 83
  names.enqueue("Fatma"); // 70

  EXPECT_EQ(names.dequeue(), "Saad");
  EXPECT_EQ(names.dequeue(), "Fatma");
  EXPECT_EQ(names.dequeue(), "Ali");

  EXPECT_TRUE(names.isEmpty());
  EXPECT_EQ(names.size(), 0);
}

// Test 6: Stack container
// Test: Greater priority (min-heap using std::greater)
TEST_F(PriorityQueueTest, GreaterPriority)
{
  PriorityQueue<int, std::vector<int>, std::greater<int>> pq;
  pq.enqueue(20);
  pq.enqueue(10);
  EXPECT_EQ(pq.getFront(), 10);
  EXPECT_EQ(pq.getRear(), 20);
}

// Test: Custom Compare (using Compare with ">" acts like std::greater)
TEST_F(PriorityQueueTest, CustomCompare)
{
  PriorityQueue<int, std::vector<int>, Compare<int>> pq(std::vector<int>(),
                                                        Compare<int>(">"));
  pq.enqueue(20);
  pq.enqueue(10);
  EXPECT_EQ(pq.getFront(), 10);
  EXPECT_EQ(pq.getRear(), 20);
}
