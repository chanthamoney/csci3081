/**
 * @file aggressive_unittest.cc
 *
 * @copyright 2019 csci3081 , All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/aggressive.h"
#include "src/behaviors.h"
#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);
 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class AggressiveBehaviorTest : public ::testing::Test {
  protected:
    double speed = 100;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(AggressiveBehaviorTest, WheelVelocityAggressiveNE) {
  Aggressive * BehaviorAggressive = new Aggressive();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorAggressive->getWheelVelocity(5, 10, speed, &testVelocityFar);
  BehaviorAggressive->getWheelVelocity(50, 100, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(10, 5));
  EXPECT_EQ(testVelocityNear, WheelVelocity(100, 50));

  // Right wheel LT Left
  EXPECT_LT(testVelocityFar.right, testVelocityFar.left);
  EXPECT_LT(testVelocityNear.right, testVelocityNear.left);

  // Closer object increases my speed
  EXPECT_GT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityFar.right);
}

TEST_F(AggressiveBehaviorTest, WheelVelocityAggressiveN) {
  Aggressive * BehaviorAggressive = new Aggressive();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorAggressive->getWheelVelocity(5, 5, speed, &testVelocityFar);
  BehaviorAggressive->getWheelVelocity(50, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(5, 5));
  EXPECT_EQ(testVelocityNear, WheelVelocity(50, 50));

  // Left wheel EQ Right
  EXPECT_EQ(testVelocityFar.left, testVelocityFar.right);
  EXPECT_EQ(testVelocityNear.left, testVelocityNear.right);

  // Closer object increases my speed
  EXPECT_GT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityFar.right);
}

TEST_F(AggressiveBehaviorTest, WheelVelocityAggressiveNW) {
  Aggressive * BehaviorAggressive = new Aggressive();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorAggressive->getWheelVelocity(10, 5, speed, &testVelocityFar);
  BehaviorAggressive->getWheelVelocity(100, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(5, 10));
  EXPECT_EQ(testVelocityNear, WheelVelocity(50, 100));

  // Left wheel LT Right
  EXPECT_LT(testVelocityFar.left, testVelocityFar.right);
  EXPECT_LT(testVelocityNear.left, testVelocityNear.right);

  // Closer object increases my speed
  EXPECT_GT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityFar.right);
}
NAMESPACE_END(csci3081);
