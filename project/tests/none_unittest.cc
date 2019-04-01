/**
 * @file none_unittest.cc
 *
 * @copyright 2019 csci3081 , All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/none.h"
#include "src/behaviors.h"
#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);
 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class NoneBehaviorTest : public ::testing::Test {
  protected:
    double speed = 100;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(NoneBehaviorTest, WheelVelocityNoneNE) {
  None * BehaviorNone = new None();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorNone->getWheelVelocity(5, 10, speed, &testVelocityFar);
  BehaviorNone->getWheelVelocity(50, 100, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(0, 0));
  EXPECT_EQ(testVelocityNear, WheelVelocity(0, 0));
}

TEST_F(NoneBehaviorTest, WheelVelocityNoneN) {
  None * BehaviorNone = new None();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorNone->getWheelVelocity(5, 5, speed, &testVelocityFar);
  BehaviorNone->getWheelVelocity(50, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(0, 0));
  EXPECT_EQ(testVelocityNear, WheelVelocity(0, 0));
}

TEST_F(NoneBehaviorTest, WheelVelocityNoneNW) {
  None * BehaviorNone = new None();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorNone->getWheelVelocity(10, 5, speed, &testVelocityFar);
  BehaviorNone->getWheelVelocity(100, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(0, 0));
  EXPECT_EQ(testVelocityNear, WheelVelocity(0, 0));
}
NAMESPACE_END(csci3081);
