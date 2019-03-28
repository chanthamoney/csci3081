/**
 * @file braitenberg_vehicle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/braitenberg_vehicle.h"
#include "src/params.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/love.h"
#include "src/explore.h"
#include "src/none.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int BraitenbergVehicle::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

BraitenbergVehicle::BraitenbergVehicle() :
  light_sensors_(), wheel_velocity_(), light_behavior_(new None()),
  food_behavior_(new None()), closest_light_entity_(NULL),
  closest_food_entity_(NULL), defaultSpeed_(5.0) {
  set_type(kBraitenberg);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  set_color(BRAITENBERG_COLOR);
  set_pose(ROBOT_INIT_POS);

  wheel_velocity_ = WheelVelocity(0, 0);

  // Set ID
  count++;
  set_id(count);
}

void BraitenbergVehicle::TimestepUpdate(__unused unsigned int dt) {
  if (collision_time_ != 0) {
    if (collision_time_ == 20) {
      set_heading(static_cast<int>((get_pose().theta - 135)) % 360);
      collision_time_ = 0;
    } else {
        collision_time_++;
    }
  }

  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  }
  UpdateLightSensors();
}

void BraitenbergVehicle::HandleCollision(__unused EntityType ent_type,
   __unused ArenaEntity * object) {
  collision_time_++;
  set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
}

void BraitenbergVehicle::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  }

  if (!closest_entity_) {
    return;
  }

  if (!*closest_entity_) {
    *closest_entity_ = &entity;
  }

  double distance = (this->get_pose()-entity.get_pose()).Length();
  double closest_distance =
  (this->get_pose()-(*closest_entity_)->get_pose()).Length();
  if (distance < closest_distance) {
    *closest_entity_ = &entity;
    closest_distance = distance;
  }
  if (closest_distance > 100.0) {
    *closest_entity_ = NULL;
  }
}

void BraitenbergVehicle::Update() {
  WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);

  double light_left_sensor_reading = get_sensor_reading_left(closest_light_entity_);
  double light_right_sensor_reading = get_sensor_reading_right(closest_light_entity_);

  light_behavior_->getWheelVelocity(light_left_sensor_reading, light_right_sensor_reading, defaultSpeed_, &light_wheel_velocity);

    //
    // switch (light_behavior_) {
    //   case kExplore:
    //     light_wheel_velocity = WheelVelocity(
    //       1.0/get_sensor_reading_right(closest_light_entity_),
    //        1.0/get_sensor_reading_left(closest_light_entity_), defaultSpeed_);
    //     break;
    //   case kLove:
    //     light_wheel_velocity = WheelVelocity(
    //       1.0/get_sensor_reading_left(closest_light_entity_),
    //       1.0/get_sensor_reading_right(closest_light_entity_), defaultSpeed_);
    //     break;
    //   case kCoward:
    //     light_wheel_velocity = WheelVelocity(
    //       get_sensor_reading_left(closest_light_entity_),
    //       get_sensor_reading_right(closest_light_entity_), defaultSpeed_);
    //     break;
    //   case kAggressive:
    //     light_wheel_velocity = WheelVelocity(
    //       get_sensor_reading_right(closest_light_entity_),
    //       get_sensor_reading_left(closest_light_entity_), defaultSpeed_);
    //     break;
    //   case kNone:
    //   default:
    //     numBehaviors--;
    //     break;
    // }
    //


  WheelVelocity food_wheel_velocity = WheelVelocity(0, 0);
  double food_left_sensor_reading = get_sensor_reading_left(closest_food_entity_);
  double food_right_sensor_reading = get_sensor_reading_right(closest_food_entity_);
  food_behavior_->getWheelVelocity(food_left_sensor_reading, food_right_sensor_reading, defaultSpeed_, &food_wheel_velocity);

  // switch (food_behavior_) {
  //   case kExplore:
  //     food_wheel_velocity = WheelVelocity(
  //       1.0/get_sensor_reading_right(closest_food_entity_),
  //       1.0/get_sensor_reading_left(closest_food_entity_), defaultSpeed_);
  //     break;
  //   case kLove:
  //     food_wheel_velocity = WheelVelocity(
  //       1.0/get_sensor_reading_left(closest_food_entity_),
  //       1.0/get_sensor_reading_right(closest_food_entity_), defaultSpeed_);
  //     break;
  //   case kCoward:
  //     food_wheel_velocity = WheelVelocity(
  //       get_sensor_reading_left(closest_food_entity_),
  //       get_sensor_reading_right(closest_food_entity_), defaultSpeed_);
  //     break;
  //   case kAggressive:
  //     food_wheel_velocity = WheelVelocity(
  //       get_sensor_reading_right(closest_food_entity_),
  //       get_sensor_reading_left(closest_food_entity_), defaultSpeed_);
  //     break;
  //   case kNone:
  //   default:
  //     numBehaviors--;
  //     break;
  // }

  // if (numBehaviors) {
  //   wheel_velocity_ = WheelVelocity(
  //     (light_wheel_velocity.left + food_wheel_velocity.left)/numBehaviors,
  //     (light_wheel_velocity.right + food_wheel_velocity.right)/numBehaviors,
  //     defaultSpeed_);
  // } else {
  //   wheel_velocity_ = WheelVelocity(0, 0);
  // }
    // set color of robot
  if ( (light_wheel_velocity.left == 0 && light_wheel_velocity.right == 0)
    && (food_wheel_velocity.left > 0 && food_wheel_velocity.right > 0)) {
      wheel_velocity_ = WheelVelocity(
        food_wheel_velocity.left, food_wheel_velocity.right, defaultSpeed_);
      set_color({0, 0, 255});
    } else if ((light_wheel_velocity.left > 0 && light_wheel_velocity.right > 0)
    && (food_wheel_velocity.left == 0 && food_wheel_velocity.right == 0)) {
      wheel_velocity_ = WheelVelocity(
        light_wheel_velocity.left, light_wheel_velocity.right, defaultSpeed_);
      set_color({255, 204, 51});
    } else {
      wheel_velocity_ = WheelVelocity(
        (light_wheel_velocity.left + food_wheel_velocity.left)/2,
        (light_wheel_velocity.right + food_wheel_velocity.right)/2,
        defaultSpeed_);
    set_color({122, 0, 25});
  }
}

std::string BraitenbergVehicle::get_name() const {
  return "Braitenberg " + std::to_string(get_id());
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors() {
  return light_sensors_;
}

double BraitenbergVehicle::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double BraitenbergVehicle::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void BraitenbergVehicle::UpdateLightSensors() {
  for (unsigned int f = 0; f < light_sensors_.size(); f++) {
    Pose& pos = light_sensors_[f];
    if (f == 0) {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta - 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta - 40));
    } else {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta + 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta + 40));
    }
  }
}

void BraitenbergVehicle::LoadFromObject(json_object* config) {
  ArenaEntity::LoadFromObject(config);
    json_object entity_config = *config;
  if (entity_config.find("light_behavior") != entity_config.end()) {
    std::string type = entity_config["light_behavior"].get<std::string>();
    if (type == "Aggressive") {
      light_behavior_ = new Aggressive();
    }
    else if (type == "Love") {
      light_behavior_ = new Love();
    }
    else if (type == "Coward") {
      light_behavior_ = new Coward();
    }
    else if (type == "Explore") {
      light_behavior_ = new Explore();
    }
    else {
      light_behavior_ = new None();
    }
  }
  if (entity_config.find("food_behavior") != entity_config.end()) {
    std::string type = entity_config["food_behavior"].get<std::string>();
    if (type == "Aggressive") {
      food_behavior_ = new Aggressive();
    }
    else if (type == "Love") {
      food_behavior_ = new Love();
    }
    else if (type == "Coward") {
      food_behavior_ = new Coward();
    }
    else if (type == "Explore") {
      food_behavior_ = new Explore();
    }
    else {
      food_behavior_ = new None();
    }
  }

  UpdateLightSensors();
}

NAMESPACE_END(csci3081);
