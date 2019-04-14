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
  light_sensors_(), wheel_velocity_(), bv_behavior_(new None()),
  light_behavior_(new None()),
  food_behavior_(new None()), closest_bv_entity_(NULL),
  closest_light_entity_(NULL),
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
  starving_time_++;
  if (isDead()) {
    return;
  }
  if (collision_time_ != 0) {
    if (collision_time_ == 20) {
      set_heading(static_cast<int>((get_pose().theta - 135)) % 360);
      collision_time_ = 0;
    } else {
        collision_time_++;
    }
  }
  if (starving_time_ == 600) {
    Die();
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
  } else if (entity.get_type() == kBraitenberg) {
    if (entity.get_id() != this->get_id() && !entity.isDead()) {
      closest_entity_ = &closest_bv_entity_;
    }
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
  if (dead_) {
    return;
  }

  Behaviors* dynamic_food_behavior;
  Behaviors* dynamic_bv_behavior;
  Behaviors* dynamic_light_behavior;

  // Set dynamic behaviors based on internal measures
  if (starving_time_ >= hungry_time_) {
    bool food_close = true;
    if (closest_food_entity_ != nullptr) {
      double distance = (get_pose()-closest_food_entity_->get_pose()).Length();
      food_close = distance < 100;

    } else {
      food_close = false;
    }

    if (food_close) {
      dynamic_food_behavior = new Aggressive();
    } else {
      dynamic_food_behavior = new Explore();
    }
    dynamic_bv_behavior = new None();
    dynamic_light_behavior = new None();
  } else {
    dynamic_food_behavior = food_behavior_;
    dynamic_bv_behavior = bv_behavior_;
    dynamic_light_behavior = light_behavior_;
  }

  WheelVelocity bv_wheel_velocity = WheelVelocity(0, 0);
  double bv_left_sensor_reading = get_sensor_reading_left(closest_bv_entity_);
  double bv_right_sensor_reading = get_sensor_reading_right(closest_bv_entity_);
  dynamic_bv_behavior->getWheelVelocity(bv_left_sensor_reading,
                                 bv_right_sensor_reading,
                                 defaultSpeed_,
                                 &bv_wheel_velocity);


  WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);

  double light_left_sensor_reading =
   get_sensor_reading_left(closest_light_entity_);
  double light_right_sensor_reading =
   get_sensor_reading_right(closest_light_entity_);

  dynamic_light_behavior->getWheelVelocity(light_left_sensor_reading,
                                    light_right_sensor_reading,
                                    defaultSpeed_,
                                    &light_wheel_velocity);

  WheelVelocity food_wheel_velocity = WheelVelocity(0, 0);
  double food_left_sensor_reading =
    get_sensor_reading_left(closest_food_entity_);
  double food_right_sensor_reading =
    get_sensor_reading_right(closest_food_entity_);

  dynamic_food_behavior->getWheelVelocity(food_left_sensor_reading,
                                   food_right_sensor_reading,
                                   defaultSpeed_,
                                   &food_wheel_velocity);

  std::vector<WheelVelocity*> wvs {&light_wheel_velocity,
                                   &food_wheel_velocity,
                                   &bv_wheel_velocity};
  Notify(&wvs);

  // FOOD, LIGHT, BV
  // NNN, NNS, NSN, NSS, SNN, SNS, SSS
  bool light_behavior_set, food_behavior_set, bv_behavior_set;
  light_behavior_set = dynamic_light_behavior->getBehaviorType() != "None";
  food_behavior_set = dynamic_food_behavior->getBehaviorType() != "None";
  bv_behavior_set = dynamic_bv_behavior->getBehaviorType() != "None";
  if (!light_behavior_set && food_behavior_set) {
    set_color({0, 0, 255});

    if (bv_behavior_set) {
      wheel_velocity_ = WheelVelocity(
        (bv_wheel_velocity.left + food_wheel_velocity.left)/2,
        (bv_wheel_velocity.right + food_wheel_velocity.right)/2,
        defaultSpeed_);
    } else {
      wheel_velocity_ = WheelVelocity(
        food_wheel_velocity.left, food_wheel_velocity.right, defaultSpeed_);
    }

  } else if (light_behavior_set && !food_behavior_set) {
    set_color({255, 204, 51});

    if (bv_behavior_set) {
      wheel_velocity_ = WheelVelocity(
        (light_wheel_velocity.left + bv_wheel_velocity.left)/2,
        (light_wheel_velocity.right + bv_wheel_velocity.right)/2,
        defaultSpeed_);
    } else {
      wheel_velocity_ = WheelVelocity(
        light_wheel_velocity.left, light_wheel_velocity.right, defaultSpeed_);
    }

  } else if (light_behavior_set && food_behavior_set) {
    set_color({122, 0, 25});

    if (bv_behavior_set) {
      wheel_velocity_ = WheelVelocity(
        (light_wheel_velocity.left + food_wheel_velocity.left +
           bv_wheel_velocity.left)/3,
        (light_wheel_velocity.right + food_wheel_velocity.right +
           bv_wheel_velocity.right)/3,
        defaultSpeed_);
    } else {
      wheel_velocity_ = WheelVelocity(
        (light_wheel_velocity.left + food_wheel_velocity.left)/2,
        (light_wheel_velocity.right + food_wheel_velocity.right)/2,
        defaultSpeed_);
    }
  } else {
    set_color({122, 0, 25});

    if (bv_behavior_set) {
      wheel_velocity_ = WheelVelocity(bv_wheel_velocity.left,
        bv_wheel_velocity.right, defaultSpeed_);
    } else {
      wheel_velocity_ = WheelVelocity(0, 0, defaultSpeed_);
    }
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
    } else if (type == "Love") {
      light_behavior_ = new Love();
    } else if (type == "Coward") {
      light_behavior_ = new Coward();
    } else if (type == "Explore") {
      light_behavior_ = new Explore();
    } else {
      light_behavior_ = new None();
    }
  }
  if (entity_config.find("food_behavior") != entity_config.end()) {
    std::string type = entity_config["food_behavior"].get<std::string>();
    if (type == "Aggressive") {
      food_behavior_ = new Aggressive();
    } else if (type == "Love") {
      food_behavior_ = new Love();
    } else if (type == "Coward") {
      food_behavior_ = new Coward();
    } else if (type == "Explore") {
      food_behavior_ = new Explore();
    } else {
      food_behavior_ = new None();
    }
  }

  if (entity_config.find("robot_behavior") != entity_config.end()) {
    std::string type = entity_config["robot_behavior"].get<std::string>();
    if (type == "Aggressive") {
      bv_behavior_ = new Aggressive();
    } else if (type == "Love") {
      bv_behavior_ = new Love();
    } else if (type == "Coward") {
      bv_behavior_ = new Coward();
    } else if (type == "Explore") {
      bv_behavior_ = new Explore();
    } else {
      bv_behavior_ = new None();
    }
  }

  UpdateLightSensors();
}

void BraitenbergVehicle::Die() {
  dead_ = true;
  set_color({220, 220, 220, 190});
  bv_behavior_ = new None();
  food_behavior_ = new None();
  light_behavior_ = new None();
}

void BraitenbergVehicle::ConsumeFood() {
  starving_time_ = 0;
}


NAMESPACE_END(csci3081);
