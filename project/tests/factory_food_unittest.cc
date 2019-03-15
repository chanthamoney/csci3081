/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/factory_food.h"
#include "src/behavior_enum.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryFoodTest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    food_factory = new  csci3081::factoryFood();
    std::string json = "{\"type\": \"Food\", \"x\":200, \"y\":200, \"r\":20, \"theta\": 0.0 }";
    json_value * myconfig = new json_value();
    std::string err = parse_json(myconfig, json);
    config = myconfig->get<json_object>();
    delete myconfig;
  }
 virtual void TearDown(){
   delete food_factory;
 }

 csci3081::factoryFood * food_factory;
json_object config;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryFoodTest, Constructor) {
  csci3081::Food * food  = food_factory->Create(&config);
  bool foodMobile = food->is_mobile();
  EXPECT_EQ(foodMobile, false);
  EXPECT_EQ(food->get_type(), csci3081::kFood);
  delete food;
}

TEST_F(FactoryFoodTest, JsonPostion) {
  csci3081::Food * food  = food_factory->Create(&config);
  csci3081::Pose foodpose = food->get_pose();
  int foodx = foodpose.x;
  int foody = foodpose.y;
  double foodTheta = foodpose.theta;
  EXPECT_EQ(foodx, 200);
  EXPECT_EQ(foody, 200);
  EXPECT_EQ(foodTheta, 0);
  delete food;
}

TEST_F(FactoryFoodTest, JsonRadius) {
  csci3081::Food * food  = food_factory->Create(&config);
  double foodRadius = food->get_radius();
  EXPECT_EQ(foodRadius, 20);
  delete food;
}

TEST_F(FactoryFoodTest, JsonColor) {
  csci3081::Food * food  = food_factory->Create(&config);
  int foodRColor = food->get_color().r;
  int foodBColor = food->get_color().b;
  int foodGColor = food->get_color().g;
  EXPECT_EQ(foodRColor, 0);
  EXPECT_EQ(foodGColor, 255);
  EXPECT_EQ(foodBColor, 0);
  delete food;
}
