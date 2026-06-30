#include "circular-queue.hpp"
#include <gtest/gtest.h>

// Test fixture for CircularQueue
class CircularQueueTest : public ::testing::Test {
protected:
  CircularQueue<int> nums;

  void SetUp() override {
    // Runs before each test
  }

  void TearDown() override {
    // Runs after each test
  }
};

// Test 1: Queue is initially empty
TEST_F(CircularQueueTest, InitiallyEmpty) {
  EXPECT_TRUE(nums.isEmpty());
  EXPECT_FALSE(nums.getFront().has_value());
  EXPECT_FALSE(nums.getRear().has_value());
  EXPECT_EQ(nums.size(), 0);
}

// Test 2: Enqueue a single element
TEST_F(CircularQueueTest, EnqueueSingleElement) {
  nums.enqueue(10);
  EXPECT_FALSE(nums.isEmpty());
  EXPECT_EQ(nums.size(), 1);
  EXPECT_EQ(nums.getFront().value(), 10);
  EXPECT_EQ(nums.getRear().value(), 10);
}

// Test 3: Enqueue multiple elements
TEST_F(CircularQueueTest, EnqueueMultipleElements) {
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);
  EXPECT_EQ(nums.size(), 3);
  EXPECT_EQ(nums.getFront().value(), 10);
  EXPECT_EQ(nums.getRear().value(), 30);
}

// Test 4: Dequeue a single element
TEST_F(CircularQueueTest, DequeueSingleElement) {
  nums.enqueue(10);
  nums.enqueue(20);
  auto val = nums.dequeue();
  ASSERT_TRUE(val.has_value());
  EXPECT_EQ(val.value(), 10);
  EXPECT_EQ(nums.size(), 1);
  EXPECT_EQ(nums.getFront().value(), 20);
}

// Test 5: Dequeue all elements
TEST_F(CircularQueueTest, DequeueAllElements) {
  nums.enqueue(10);
  nums.enqueue(20);
  nums.enqueue(30);

  EXPECT_EQ(nums.dequeue().value(), 10);
  EXPECT_EQ(nums.dequeue().value(), 20);
  EXPECT_EQ(nums.dequeue().value(), 30);

  EXPECT_TRUE(nums.isEmpty());
  EXPECT_FALSE(nums.getFront().has_value());
  EXPECT_FALSE(nums.getRear().has_value());
}

// Test 6: Multiple enqueue/dequeue cycles
TEST_F(CircularQueueTest, MultipleEnqueueDequeueCycles) {
  for (int i = 1; i <= 5; i++)
    nums.enqueue(i * 10);
  EXPECT_EQ(nums.size(), 5);
  EXPECT_EQ(nums.getFront().value(), 10);
  EXPECT_EQ(nums.getRear().value(), 50);

  for (int i = 0; i < 3; i++)
    nums.dequeue();
  EXPECT_EQ(nums.size(), 2);
  EXPECT_EQ(nums.getFront().value(), 40);

  nums.enqueue(60);
  nums.enqueue(70);
  nums.enqueue(80);
  EXPECT_EQ(nums.size(), 5);
  EXPECT_EQ(nums.getRear().value(), 80);
}

// Test 7: Stress test with large number of operations
TEST_F(CircularQueueTest, StressTestLargeOperations) {
  for (int i = 0; i < 1000; i++)
    nums.enqueue(i);

  for (int i = 0; i < 500; i++)
    nums.dequeue();

  EXPECT_EQ(nums.size(), 500);
  EXPECT_EQ(nums.getFront().value(), 500);
  EXPECT_EQ(nums.getRear().value(), 999);
}
