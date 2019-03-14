/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/arena.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/factory_food.h"
#include "src/food.h"
#include "src/arena_immobile_entity.h"
#include "src/arena_entity.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryFoodTest : public ::testing::Test {

 protected:
   csci3081::factoryFood food_factory;

   std::string json = "{\"type\": \"Food\", \"x\":200, \"y\":200, \"r\":20, \"theta\": 0.0 }";
   json_value* myconfig = new json_value();
   // std::string err = parse_json(*myconfig, json);
   // if (!err.empty()) {
   //   std::cerr << "Parse error: " << err << std::endl;
   //   delete myconfig;
   //   myconfig = NULL;
   // }
   json_object config = myconfig->get<json_object>();
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryFoodTest, Constructor){
  auto food = food_factory.Create(&config);
  // Testing position of bv
  csci3081::Pose foodPose = food->get_pose();
  int foodx = foodPose.x;
  int foody = foodPose.y;
  double foodTheta = foodPose.theta;
  //TODO: provide real values later
  EXPECT_EQ(foodx, 1);
  EXPECT_EQ(foody, 1);
  EXPECT_NEAR(foodTheta, 0, 10);

  //Testing radius of bv
  double foodRadius = food->get_radius();
  EXPECT_NEAR(foodRadius, 0, 10);


  //testing mobile
  bool foodMobile = food->is_mobile();
  EXPECT_EQ(foodMobile, false);

  //testing color
  int foodRColor = food->get_color().r;
  int foodBColor = food->get_color().b;
  int foodGColor = food->get_color().g;
  EXPECT_EQ(foodRColor, 0);
  EXPECT_EQ(foodBColor, 0);
  EXPECT_EQ(foodGColor, 0);

  //Test type
  EXPECT_EQ(food->get_type(), csci3081::kFood);

}
