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
    json_value * myconfig = new json_value();
    if(myconfig->is<json_object>()) {
      config = myconfig->get<json_object>();
    }
    config.insert(std::make_pair("type", picojson::value("Food")));
    double x, y, r, theta;
    x = 200;
    y = 200;
    r = 20;
    theta = 0.0;
    config.insert(std::make_pair("x", picojson::value(x)));
    config.insert(std::make_pair("y", picojson::value(y)));
    config.insert(std::make_pair("r", picojson::value(r)));
    config.insert(std::make_pair("theta", picojson::value(theta)));
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
