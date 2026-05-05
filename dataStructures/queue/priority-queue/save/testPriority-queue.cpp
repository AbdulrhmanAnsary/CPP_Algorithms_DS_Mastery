#include "priority-queue.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

class PriorityQueueTest : public ::testing::Test {
protected:
  PriorityQueue<int> nums;
  PriorityQueue<std::string> names;

  void SetUp() override {}
  void TearDown() override {}
};

// Test 1: Priority queue is initially empty
TEST_F(PriorityQueueTest, InitiallyEmpty) {
  // int
  EXPECT_TRUE(nums.isEmpty());
  EXPECT_THROW(nums.dequeue(), std::runtime_error);
  EXPECT_THROW(nums.getFront(), std::runtime_error);
  EXPECT_THROW(nums.getRear(), std::runtime_error);
  EXPECT_EQ(nums.size(), 0);

  // string
  EXPECT_TRUE(names.isEmpty());
  EXPECT_THROW(names.dequeue(), std::runtime_error);
  EXPECT_THROW(names.getFront(), std::runtime_error);
  EXPECT_THROW(names.getRear(), std::runtime_error);
  EXPECT_EQ(names.size(), 0);
}

// Test 2: Enqueue a single element
TEST_F(PriorityQueueTest, EnqueueSingleElement) {
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
TEST_F(PriorityQueueTest, EnqueueMultipleElements) {
  // int
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);
  EXPECT_EQ(nums.size(), 3);
  EXPECT_EQ(nums.getFront(), 30);
  EXPECT_EQ(nums.getRear(), 10);

  // string
  names.enqueue("Ali");   // 65
  names.enqueue("Saad");  // 83
  names.enqueue("Fatma"); // 70
  EXPECT_EQ(nums.size(), 3);
  EXPECT_EQ(nums.getFront(), "Saad");
  EXPECT_EQ(nums.getRear(), "Ali");
}

// Test 4: Dequeue a single element
TEST_F(PriorityQueueTest, DequeueSingleElement) {
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
  EXPECT_EQ(nums.size(), 1);
  EXPECT_EQ(nums.getFront(), "Saad");
  EXPECT_EQ(nums.getRear(), "Saad");
}

// Test 5: Dequeue all elements
TEST_F(PriorityQueueTest, DequeueAllElements) {
  // int
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);

  EXPECT_EQ(nums.dequeue(), 10);
  EXPECT_EQ(nums.dequeue(), 20);
  EXPECT_EQ(nums.dequeue(), 30);

  EXPECT_TRUE(nums.isEmpty());
  EXPECT_FALSE(nums.getFront());
  EXPECT_FALSE(nums.getRear());

  // string
  names.enqueue("Ali");   // 65
  names.enqueue("Saad");  // 83
  names.enqueue("Fatma"); // 70

  EXPECT_EQ(names.dequeue(), "Saad");
  EXPECT_EQ(names.dequeue(), "Fatma");
  EXPECT_EQ(names.dequeue(), "Ali");

  EXPECT_TRUE(names.isEmpty());
  EXPECT_THROW(names.getFront(), std::runtime_error);
  EXPECT_THROW(names.getRear(), std::runtime_error);
}

// Test 6: Stack container
TEST(StackContainer, EnqueueSingleElement) {
  // int
  PriorityQueue<int, std::stack<int>> evenNums;

  // string
  PriorityQueue<int, std::stack<int>> frindNames;
}

// Custom container
template <class T> class Node {
public:
  using value_type = T;
  T value;
  T *next = nullptr;
};

// Test 7: Custom container
TEST_F(PriorityQueueTest, CustomContainer) {
  // int
  PriorityQueue<int, Node<int>> oodNums;
}

// Test 8: Greater priority
TEST_F(PriorityQueueTest, GreaterPriority) {
  // int
  PriorityQueue<int, std::vector<int>, std::greater<int>> nums;
}

// Custom Compare
template <class T> class Compare {
  std::string op;

public:
  Compare(const std::string &op) : op(op) {
    if (op != "<" && op != ">" && op != "<=" && op != ">=" && op != "=") {
      throw std::runtime_error(
          "Invalid operator error, Enter ('<', '>', '<=', '>=', '=')");
    }
  }

  bool operator()(const T &a, const T &b) const {
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
// Test 9: Custom Compare
TEST_F(PriorityQueueTest, CustomCompare) {
  // int
  PriorityQueue<int, std::vector<int>, Compare<int>> pq(std::vector<int>(),
                                                        Compare<int>(">"));
}
