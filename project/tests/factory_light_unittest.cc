/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/arena.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/factory_light.h"
#include "src/arena_mobile_entity.h"
#include "src/light.h"
#include "src/arena_entity.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryLightTest : public ::testing::Test {

 protected:
   csci3081::factoryLight light_factory;

   std::string json = "{\"type\": \"Light\", \"x\":150, \"y\":300, \"r\":25 }";
   json_value* myconfig = new json_value();
   // std::string err = parse_json(*myconfig, json);
   // if (! err.empty()) {
   //   std::cerr << "Parse error: " << err << std::endl;
   //   delete myconfig;
   //   myconfig = NULL;
   // }
   std::string err = parse_json(myconfig, json);

   json_object config = myconfig->get<json_object>();

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryLightTest, Constructor){
  auto light = light_factory.Create(&config);
  // Testing position of light
  csci3081::Pose lightPose = light->get_pose();
  int lightx = lightPose.x;
  int lighty = lightPose.y;
  double lightTheta = lightPose.theta;
  //TODO: provide real values later
  EXPECT_EQ(lightx, 1);
  EXPECT_EQ(lighty, 1);
  EXPECT_NEAR(lightTheta, 0, 10);

  //Testing radius of light
  double lightRadius = light->get_radius();
  EXPECT_NEAR(lightRadius, 0, 10);

  //Testing speed of light
  double lightSpeed = light->get_speed();
  EXPECT_NEAR(lightSpeed, 0, 10);

  //testing mobile
  bool lightMobile = light->is_moving();
  EXPECT_EQ(lightMobile, true);

  //testing color
  int lightRColor = light->get_color().r;
  int lightBColor = light->get_color().b;
  int lightGColor = light->get_color().g;
  EXPECT_EQ(lightRColor, 0);
  EXPECT_EQ(lightBColor, 0);
  EXPECT_EQ(lightGColor, 0);

  //Test type
  EXPECT_EQ(light->get_type(), csci3081::kLight);
}
