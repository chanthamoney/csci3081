/**
 * @file coward_unittest.cc
 *
 * @copyright 2019 csci3081 , All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/coward.h"
#include "src/behaviors.h"
#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);
 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class CowardBehaviorTest : public ::testing::Test {
  protected:
    double speed = 100;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(CowardBehaviorTest, WheelVelocityCowardNE) {
  Coward * BehaviorCoward = new Coward();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorCoward->getWheelVelocity(5, 10, speed, &testVelocityFar);
  BehaviorCoward->getWheelVelocity(50, 100, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(5, 10));
  EXPECT_EQ(testVelocityNear, WheelVelocity(50, 100));

  // Right wheel GT Left
  EXPECT_GT(testVelocityFar.right, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityNear.left);

  // Closer object increases my speed
  EXPECT_GT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityFar.right);
}

TEST_F(CowardBehaviorTest, WheelVelocityCowardN) {
  Coward * BehaviorCoward = new Coward();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorCoward->getWheelVelocity(5, 5, speed, &testVelocityFar);
  BehaviorCoward->getWheelVelocity(50, 50, speed, &testVelocityNear);

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

TEST_F(CowardBehaviorTest, WheelVelocityCowardNW) {
  Coward * BehaviorCoward = new Coward();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorCoward->getWheelVelocity(10, 5, speed, &testVelocityFar);
  BehaviorCoward->getWheelVelocity(100, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(10, 5));
  EXPECT_EQ(testVelocityNear, WheelVelocity(100, 50));

  // Left wheel GT Right
  EXPECT_GT(testVelocityFar.left, testVelocityFar.right);
  EXPECT_GT(testVelocityNear.left, testVelocityNear.right);

  // Closer object increases my speed
  EXPECT_GT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityFar.right);
}
NAMESPACE_END(csci3081);
