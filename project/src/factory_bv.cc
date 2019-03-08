/**
 * @file factory_bv.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 #include "src/common.h"
 #include "src/entity_type.h"
 #include "src/factory_bv.h"
 #include "src/params.h"
 #include "src/pose.h"
 #include "src/rgb_color.h"
 #include "src/behavior_enum.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

factoryBraitenberg::factoryBraitenberg(){}; //TODO: Constructor What should I do..

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

 BraitenbergVehicle* factoryBraitenberg::Create(__unused json_object& config){ //create entity here
   // double theta, x, y, r;
   // std::string light_behavior, food_behavior;
   // x = std::stod(config["x"]);
   // y = std::stod(config["y"]);
   // r = std::stod(config["r"]);
   // theta = std::stod(config["theta"]);
   // light_behavior = config["light_behavior"];
   // food_behavior = config["food_behavior"];
   //
   // auto * braitenbergVehicle = new BraitenbergVehicle;
   // braitenbergVehicle->set_type(kBraitenberg);
   // braitenbergVehicle->set_color(BRAITENBERG_COLOR);
   // braitenbergVehicle->set_radius(r);
   // Pose pose = new Pose(x, y, theta);
   // braitenbergVehicle->set_pose(pose);
   // braitenbergVehicle->set_light_behavior(get_behavior_type(light_behavior));
   // braitenbergVehicle->set_food_behavior(get_behavior_type(food_behavior));
   // vehicle_count_++;
   // braitenbergVehicle->set_id(vehicle_count_);
   BraitenbergVehicle * braitenbergVehicle = new BraitenbergVehicle;
   braitenbergVehicle->LoadFromObject(config);
   return braitenbergVehicle;
 };


NAMESPACE_END(csci3081);
