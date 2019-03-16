/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/factory_bv.h"
#include "src/behavior_enum.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryBvTest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    bv_factory = new csci3081::factoryBraitenberg();
    std::string json = "{\"type\": \"Braitenberg\", \"x\":270, \"y\":270, \"r\":15, \"theta\": 215, \"light_behavior\": \"None\", \"food_behavior\": \"Explore\" }";
    json_value * myconfig = new json_value();
    std::string err = parse_json(myconfig, json);
    config = myconfig->get<json_object>();
    delete myconfig;
  }
 virtual void TearDown(){
   delete bv_factory;
 }

csci3081::factoryBraitenberg * bv_factory;
json_object config;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryBvTest, Constructor) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  bool bvMobile = bv->is_moving();
  EXPECT_EQ(bvMobile, true);
  EXPECT_EQ(bv->get_type(), csci3081::kBraitenberg);
  delete bv;
}

TEST_F(FactoryBvTest, JsonPostion) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  csci3081::Pose bvpose = bv->get_pose();
  int bvx = bvpose.x;
  int bvy = bvpose.y;
  double bvTheta = bvpose.theta;
  EXPECT_EQ(bvx, 270);
  EXPECT_EQ(bvy, 270);
  EXPECT_EQ(bvTheta, 215);
  delete bv;
}

TEST_F(FactoryBvTest, JsonRadius) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  double bvRadius = bv->get_radius();
  EXPECT_EQ(bvRadius, 15);
  delete bv;
}

TEST_F(FactoryBvTest, JsonColor) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  int bvRColor = bv->get_color().r;
  int bvBColor = bv->get_color().b;
  int bvGColor = bv->get_color().g;
  EXPECT_EQ(bvRColor, 122);
  EXPECT_EQ(bvBColor, 25);
  EXPECT_EQ(bvGColor, 0);
  delete bv;
}

TEST_F(FactoryBvTest, JsonFoodBehavior) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  EXPECT_EQ(bv->get_food_behavior(), csci3081::kExplore);
  delete bv;
}

TEST_F(FactoryBvTest, JsonLightBehavior) {
  csci3081::BraitenbergVehicle * bv  = bv_factory->Create(&config);
  EXPECT_EQ(bv->get_light_behavior(), csci3081::kNone);
  delete bv;
}
