/**
 * @file braitenberg_decorator.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "src/braitenberg_decorator.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

BvDecorator::BvDecorator(Predator *predator) : predator_(predator) {
       predator_->set_color(BRAITENBERG_COLOR);
       predator->set_radius(DEFAULT_RADIUS);
}

/**
 * @brief Get the name of the underlying arena entity
 *
 * @return Name of the entity.
 */
std::string BvDecorator::get_name() const {
  return predator_->get_name();
}

void BvDecorator::TimestepUpdate(__unused unsigned int dt)  {
  if (predator_ != NULL) {
    set_pose(predator_->get_pose());

    if (dynamic_food_behavior_ == nullptr) {
      dynamic_food_behavior_ = getRandomBehavior();
      // dynamic_food_behavior_ = new None();
    }
    if (dynamic_light_behavior_ == nullptr) {
      dynamic_light_behavior_ = getRandomBehavior();
      // dynamic_light_behavior_ = new None();
    }

    dynamic_bv_behavior_ = new Aggressive();
    set_bv_behavior(dynamic_bv_behavior_);
    set_food_behavior(dynamic_food_behavior_);
    set_light_behavior(dynamic_light_behavior_);
    set_no_disguise(false);
    BraitenbergVehicle::UpdateLightSensors();
     //
     double pred_light_left_sensor_reading =
      predator_->get_sensor_reading_left(
        predator_->get_closest_light_entity());
     double pred_light_right_sensor_reading =
      predator_->get_sensor_reading_right(
        predator_->get_closest_light_entity());

     double pred_food_left_sensor_reading =
      predator_->get_sensor_reading_left(
        predator_->get_closest_food_entity());
     double pred_food_right_sensor_reading =
      predator_->get_sensor_reading_right(
        predator_->get_closest_food_entity());

     double pred_bv_left_sensor_reading =
      predator_->get_sensor_reading_left(
        predator_->get_closest_bv_entity());
     double pred_bv_right_sensor_reading =
      predator_->get_sensor_reading_right(
        predator_->get_closest_bv_entity());

     set_bv_left_sensor_reading(pred_bv_left_sensor_reading);
     set_bv_right_sensor_reading(pred_bv_right_sensor_reading);
     set_food_left_sensor_reading(pred_food_left_sensor_reading);
     set_food_right_sensor_reading(pred_food_right_sensor_reading);
     set_light_left_sensor_reading(pred_light_left_sensor_reading);
     set_light_right_sensor_reading(pred_light_right_sensor_reading);

    BraitenbergVehicle::TimestepUpdate(1);
    predator_->set_color(BraitenbergVehicle::get_color());
    predator_->set_wv(BraitenbergVehicle::get_wv());
    predator_->set_pose(get_pose());
  }
}

NAMESPACE_END(csci3081);
