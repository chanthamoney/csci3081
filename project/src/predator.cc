/**
 * @file predator.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/predator.h"
#include "src/braitenberg_vehicle.h"
#include "src/params.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/love.h"
#include "src/explore.h"
#include "src/none.h"
#include "src/food_decorator.h"
#include "src/light_decorator.h"
#include "src/braitenberg_decorator.h"
class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int Predator::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

Predator::Predator() :
  light_sensors_(), wheel_velocity_(), bv_behavior_(new Aggressive()),
  light_behavior_(new Coward()), food_behavior_(new None()),
  closest_bv_entity_(NULL), closest_light_entity_(NULL),
  closest_food_entity_(NULL), closest_pred_entity_(NULL), defaultSpeed_(5.0) {
  set_type(kPredator);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  set_color(PREDATOR_COLOR);
  set_pose(Pose(250, 250, 0));

  wheel_velocity_ = WheelVelocity(0, 0);

  // Set ID
  count++;
  set_id(count);
}

void Predator::TimestepUpdate(__unused unsigned int dt) {
  starving_time_++;

  // Checking if the predator is dead
  if (!isDead() && disguised_ == kFood) {
    Update();
  }


  // CHOOSING WHAT DIGUISE THE PREDATOR SHOULD WEAR
  std::cout << "STARVING TIME: " << starving_time_ << std::endl;
  if(starving_time_ == 150) {
    getDisguise();
  }
   if ( starving_time_ == 300) {
    getDisguise();
  }
   if (starving_time_ == 450) {
    getDisguise();
  }

  if (collision_time_ != 0) {
    if (collision_time_ == 20 &&
       (disguised_ == kPredator || disguised_ == kBraitenberg)) {
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

void Predator::HandleCollision(__unused EntityType ent_type,
   __unused ArenaEntity * object) {
  collision_time_++;
  set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
}

void Predator::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  } else if (entity.get_type() == kPredator) {
    if (entity.get_id() != this->get_id()) {
      closest_entity_ = &closest_pred_entity_;
    } // to assert that the entity is a kBraitenberg and if its digused as kBraitenberg it shouldn't move
  } else if (entity.get_type() == kBraitenberg && entity.get_true_type() != kPredator) {
    if (!entity.isDead()) {
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

void Predator::Update() {

  WheelVelocity bv_wheel_velocity = WheelVelocity(0, 0);
  WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);

  if (isDead()) {
       bv_wheel_velocity = WheelVelocity(0, 0);
       light_wheel_velocity = WheelVelocity(0, 0);
      return;
  }
  if (!dead_ && disguised_ == kPredator) {

  double bv_left_sensor_reading = get_sensor_reading_left(closest_bv_entity_);
  double bv_right_sensor_reading = get_sensor_reading_right(closest_bv_entity_);
  bv_behavior_->getWheelVelocity(bv_left_sensor_reading,
    bv_right_sensor_reading, defaultSpeed_, &bv_wheel_velocity);

  double light_left_sensor_reading =
   get_sensor_reading_left(closest_light_entity_);
  double light_right_sensor_reading =
   get_sensor_reading_right(closest_light_entity_);

  light_behavior_->getWheelVelocity(light_left_sensor_reading,
    light_right_sensor_reading, defaultSpeed_, &light_wheel_velocity);

  wheel_velocity_ = WheelVelocity(
    (light_wheel_velocity.left + bv_wheel_velocity.left)/2,
    (light_wheel_velocity.right + bv_wheel_velocity.right)/2,
    defaultSpeed_);
  }
  // If we are digusied as light or food just use timestep update (immobile)
  else if (disguised_ == kFood) {
    wheel_velocity_ = WheelVelocity(0, 0, 0);
    disguisedPredator_->TimestepUpdate(1);
  }
  else if (disguised_ == kLight) {
    disguisedPredator_->TimestepUpdate(1);
  }
  // If we are disguised as bv call update and do bv's update
  else {
    // static_cast<BraitenbergVehicle*>(disguisedPredator_)->Update();
    disguisedPredator_->Update();
  //  disguisedPredator_->TimestepUpdate(1);
  }
}

std::string Predator::get_name() const {
  return "Predator " + std::to_string(get_id());
}

std::vector<Pose> Predator::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> Predator::get_light_sensors() {
  return light_sensors_;
}

double Predator::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double Predator::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void Predator::UpdateLightSensors() {
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

void Predator::LoadFromObject(json_object* config) {
  ArenaEntity::LoadFromObject(config);
    json_object entity_config = *config;
  UpdateLightSensors();
}

void Predator::Die() {
  dead_ = true;
  set_color({220, 220, 220, 190});
  bv_behavior_ = new None();
  food_behavior_ = new None();
  light_behavior_ = new None();
  wheel_velocity_ = WheelVelocity(0, 0);
  delete disguisedPredator_;
  disguisedPredator_ = nullptr;
  disguised_ = kPredator;
  set_radius(DEFAULT_RADIUS);
}


// void Predator::unwrapPredator() {
//   disguisedPredator_ = nullptr;
//   disguised_ = kPredator;
//   set_color(PREDATOR_COLOR);
// }

void Predator::ConsumeBV() {
  starving_time_ = 0;
  //unwrap predator
  if(disguisedPredator_ != nullptr) {
    //  unwrapPredator();
    delete disguisedPredator_;
    disguisedPredator_ = nullptr;
    disguised_ = kPredator;
    set_color(PREDATOR_COLOR);
    possibleDisguised[0] = false;
    possibleDisguised[1] = false;
    possibleDisguised[2] = false;
    set_radius(DEFAULT_RADIUS);
  }

}
// TODO:
// bool array to tell if I was a diguised. Index 0 is food, 1 is light, 2 is bv.
// bool possibleDisguised[3] = {false};

void Predator::getDisguise() {
  int randomNumber = random_num(0, 3); //  get number between 0 and 2
  while(possibleDisguised[randomNumber]) {
      randomNumber = random_num(0, 3);
  } //while we haven't been this disguised
  if(randomNumber == 0) {
    FoodDecorator * FoodPredator = new FoodDecorator(this);
    disguised_ = kFood;
    possibleDisguised[0] = true;
    if(disguisedPredator_ != nullptr) {
      delete disguisedPredator_;
      disguisedPredator_ = FoodPredator;
    }
    else {
      disguisedPredator_ = FoodPredator;
    }
  }
  else if (randomNumber == 1) {
    LightDecorator * LightPredator = new LightDecorator(this);
    disguised_ = kLight;
    possibleDisguised[1] = true;
    if(disguisedPredator_ != nullptr) {
      delete disguisedPredator_;
      disguisedPredator_ = LightPredator;
    }
    else {
        disguisedPredator_ = LightPredator;
    }
  }
  else {
    //  random number is 3
    BvDecorator * BvPredator = new BvDecorator(this);
    disguised_ = kBraitenberg;
    possibleDisguised[2] = true;
    if(disguisedPredator_ != nullptr) {
      delete disguisedPredator_;
      disguisedPredator_ = BvPredator;
    }
    else{
      disguisedPredator_ = BvPredator;
    }
  }
}

NAMESPACE_END(csci3081);
