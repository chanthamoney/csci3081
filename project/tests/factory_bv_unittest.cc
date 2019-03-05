/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/arena.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/factory_bv.h"
#include "src/arena_mobile_entity.h"
#include "src/braitenberg_vehicle.h"
#include "src/arena_entity.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryBvTest : public ::testing::Test {

 protected:
   csci3081::factoryBraitenberg bv_factory;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryBvTest, Constructor){
  auto bv = bv_factory.Create();
  // Testing position of bv
  csci3081::Pose bvpose = bv->get_pose();
  int bvx = bvpose.x;
  int bvy = bvpose.y;
  double bvTheta = bvpose.theta;
  //TODO: provide real values later
  EXPECT_EQ(bvx, 1);
  EXPECT_EQ(bvy, 1);
  EXPECT_NEAR(bvTheta, 0, 10);

  //Testing radius of bv
  double bvRadius = bv->get_radius();
  EXPECT_NEAR(bvRadius, 0, 10);

  //Testing speed of bv
  double bvSpeed = bv->get_speed();
  EXPECT_NEAR(bvSpeed, 0, 10);

  //testing mobile
  bool bvMobile = bv->is_moving();
  EXPECT_EQ(bvMobile, true);

  //testing color
  int bvRColor = bv->get_color().r;
  int bvBColor = bv->get_color().b;
  int bvGColor = bv->get_color().g;
  EXPECT_EQ(bvRColor, 0);
  EXPECT_EQ(bvBColor, 0);
  EXPECT_EQ(bvGColor, 0);

  //Test type
  EXPECT_EQ(bv->get_type(), csci3081::kBraitenberg);

}
