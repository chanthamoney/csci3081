/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "src/factory_light.h"
#include "src/behavior_enum.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryLightTest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    light_factory = new  csci3081::factoryLight();
    std::string json = "{\"type\": \"Light\", \"x\":150, \"y\":300, \"r\":25 }";
    json_value * myconfig = new json_value();
    std::string err = parse_json(myconfig, json);
    config = myconfig->get<json_object>();
    delete myconfig;
  }
 virtual void TearDown(){
   delete light_factory;
 }

 csci3081::factoryLight * light_factory;
json_object config;

};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryLightTest, Constructor) {
  csci3081::Light * light  = light_factory->Create(&config);
  bool lightMobile = light->is_moving();
  EXPECT_EQ(lightMobile, true);
  EXPECT_EQ(light->get_type(), csci3081::kLight);
  delete light;
}

TEST_F(FactoryLightTest, JsonPostion) {
  csci3081::Light * light  = light_factory->Create(&config);
  csci3081::Pose lightpose = light->get_pose();
  int lightx = lightpose.x;
  int lighty = lightpose.y;
  EXPECT_EQ(lightx, 150);
  EXPECT_EQ(lighty, 300);
  delete light;
}

TEST_F(FactoryLightTest, JsonRadius) {
  csci3081::Light * light  = light_factory->Create(&config);
  double lightRadius = light->get_radius();
  EXPECT_EQ(lightRadius, 25);
  delete light;
}

TEST_F(FactoryLightTest, JsonColor) {
  csci3081::Light * light  = light_factory->Create(&config);
  int lightRColor = light->get_color().r;
  int lightBColor = light->get_color().b;
  int lightGColor = light->get_color().g;
  EXPECT_EQ(lightRColor, 255);
  EXPECT_EQ(lightBColor, 255);
  EXPECT_EQ(lightGColor, 255);
  delete light;
}
