#include "queue.hpp"
#include "gtest/gtest.h"
#include <string>
#include <vector>

// Test data (constants)
const std::vector<int> testNums = {12, 13, 14, 15, 16, 17, 18};
const std::vector<std::string> testNames = {
    "Ahmed", "Saad", "Ramadan", "Karim", "Mostafa", "Tarek", "Fares"};

// Test fixture class for queue tests
class QueueTest : public ::testing::Test
{
protected:
  Queue<int> nums;
  Queue<std::string> names;

  void SetUp() override
  {
    // Initialize queues before each test
    nums.enqueue(testNums);
    names.enqueue(testNames);
  }

  void TearDown() override
  {
    // Cleanup if needed
  }
};

// ✅ Test: Dequeue all elements and check correctness
TEST_F(QueueTest, DequeueAllElements)
{
  for (size_t i = 0; i < testNums.size(); ++i)
  {
    EXPECT_EQ(nums.dequeue(), testNums[i]);
    EXPECT_EQ(names.dequeue(), testNames[i]);
  }
  EXPECT_TRUE(nums.empty());
  EXPECT_TRUE(names.empty());
}

// ✅ Test: Initial state after setup
TEST_F(QueueTest, InitiallyNotEmpty)
{
  EXPECT_FALSE(nums.empty());
  EXPECT_FALSE(names.empty());
  EXPECT_EQ(nums.getFront(), testNums[0]);
  EXPECT_EQ(names.getFront(), testNames[0]);
}

// ✅ Test: Enqueue single items and verify
TEST_F(QueueTest, EnqueueSingleItems)
{
  Queue<int> localQueue; // Independent queue for this test

  EXPECT_TRUE(localQueue.empty());

  localQueue.enqueue(45);
  EXPECT_EQ(localQueue.dequeue(), 45);

  localQueue.enqueue(46);
  EXPECT_EQ(localQueue.dequeue(), 46);

  localQueue.enqueue(47);
  EXPECT_EQ(localQueue.getFront(), 47);

  EXPECT_FALSE(localQueue.empty());
}
