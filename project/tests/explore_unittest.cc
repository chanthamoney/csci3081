/**
 * @file explore_unittest.cc
 *
 * @copyright 2019 csci3081 , All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/explore.h"
#include "src/behaviors.h"
#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);
 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class ExploreBehaviorTest : public ::testing::Test {
  protected:
    double speed = 100;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(ExploreBehaviorTest, WheelVelocityExploreNE) {
  Explore * BehaviorExplore = new Explore();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorExplore->getWheelVelocity(5, 10, speed, &testVelocityFar);
  BehaviorExplore->getWheelVelocity(50, 100, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(1.0/10, 1.0/5));
  EXPECT_EQ(testVelocityNear, WheelVelocity(1.0/100, 1.0/50));

  // Right wheel GT Left
  EXPECT_GT(testVelocityFar.right, testVelocityFar.left);
  EXPECT_GT(testVelocityNear.right, testVelocityNear.left);

  // Closer object decrease my speed
  EXPECT_LT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_LT(testVelocityNear.right, testVelocityFar.right);
}

TEST_F(ExploreBehaviorTest, WheelVelocityExploreN) {
  Explore * BehaviorExplore = new Explore();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorExplore->getWheelVelocity(5, 5, speed, &testVelocityFar);
  BehaviorExplore->getWheelVelocity(50, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(1.0/5, 1.0/5));
  EXPECT_EQ(testVelocityNear, WheelVelocity(1.0/50, 1.0/50));

  // Left wheel EQ Right
  EXPECT_EQ(testVelocityFar.left, testVelocityFar.right);
  EXPECT_EQ(testVelocityNear.left, testVelocityNear.right);

  // Closer object decrease my speed
  EXPECT_LT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_LT(testVelocityNear.right, testVelocityFar.right);
}

TEST_F(ExploreBehaviorTest, WheelVelocityExploreNW) {
  Explore * BehaviorExplore = new Explore();
  WheelVelocity testVelocityFar = WheelVelocity(0,0);
  WheelVelocity testVelocityNear = WheelVelocity(0,0);
  BehaviorExplore->getWheelVelocity(10, 5, speed, &testVelocityFar);
  BehaviorExplore->getWheelVelocity(100, 50, speed, &testVelocityNear);

  // Exact implementation
  EXPECT_EQ(testVelocityFar, WheelVelocity(1.0/5, 1.0/10));
  EXPECT_EQ(testVelocityNear, WheelVelocity(1.0/50, 1.0/100));

  // Left wheel GT Right
  EXPECT_GT(testVelocityFar.left, testVelocityFar.right);
  EXPECT_GT(testVelocityNear.left, testVelocityNear.right);

  // Closer object decrease my speed
  EXPECT_LT(testVelocityNear.left, testVelocityFar.left);
  EXPECT_LT(testVelocityNear.right, testVelocityFar.right);
}
NAMESPACE_END(csci3081);
