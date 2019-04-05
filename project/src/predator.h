/**
 * @file predator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PREDATOR_VEHICLE_H_
#define SRC_PREDATOR_VEHICLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/wheel_velocity.h"
#include "src/behaviors.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Entity class to represent a Predator.
 *
 * A predator vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Predator contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class Predator : public ArenaMobileEntity {
 public:

  /**
   * @brief Default constructor.
   */
  Predator();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  /**
  *  @brief Deleting the copy constructor.
  */
  Predator(const Predator & rhs) = delete;
  /**
  *  @brief Deleting the copy assignment.
  */
  Predator operator=(const Predator & rhs) = delete;

  /**
   * @brief Update the Predator's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;
  /**
   * @brief Update the Predator's wheel velocity based on the
   * behaviors set by light_behavior_ and food_behavior_
   *
   */
  void Update() override;

  /**
   * @brief Change the movement state of the Predator.
   * When a collision occurs, the Predator will turn 180 degrees,
   * move 20 timesteps, and then turn the heading 45 degrees (turn left).
   *
   * @param[in] ent_type The type of ArenaEntity the Predator collided with
   * @param[in] object ArenaEntity object that the Predator collided with
   *
   */
  void HandleCollision(EntityType ent_type,
                       ArenaEntity * object = NULL) override;

 /**
  * @brief Senses or Identify, the entity that are in the range of the Predator's
  * sensor. Then this will update the closest_entity (either food or light).
  *
  * @param[in] entity The AreanEntity that is sense by the Predator.
  */
  void SenseEntity(const ArenaEntity& entity);
  /**
   * @brief Get the name of the Predator.
   *
   * @return Returns a string
   */
  std::string get_name() const override;
  /**
   * @brief Get the immutable light sensors.
   *
   * @returns Returns a const vector<pose>
   */
  std::vector<Pose> get_light_sensors_const() const;
  /**
   * @brief Get the light sensors.
   *
   * @returns Returns a const vector<pose>
   */
  std::vector<Pose> get_light_sensors();
  /**
   * @brief Update the position and direction of the light sensor
   * To match the direction that the Predator is facing.
   *
   */
  void UpdateLightSensors();
  /**
   * @brief Takes in json_object and gets the configuration from the object.
   * The configuration from the object consist of the Type of entity (Predator),
   * light_behavior, food_behavior, radius, x, y, and theta position.
   *
   * @param[in] entity_config The json_object pointer to the configuration that for the Predator
   */
  void LoadFromObject(json_object* entity_config) override;
  /**
   * @brief Get the bv_behavior.
   *
   * @return Returns the type behavior of bv
   */
  Behaviors * get_bv_behavior() { return bv_behavior_; }
  /**
   * @brief Set the behavior for bv.
   *
   * @param[in] behavior The new bv_behavior.
   */
  void set_bv_behavior(Behaviors * behavior) { bv_behavior_ = behavior; }

  /**
   * @brief Get the light_behavior.
   *
   * @return Returns the type behavior of Light
   */
  Behaviors * get_light_behavior() { return light_behavior_; }
  /**
   * @brief Set the behavior for light.
   *
   * @param[in] behavior The new light_behavior.
   */
  void set_light_behavior(Behaviors * behavior) { light_behavior_ = behavior; }
  /**
   * @brief Get the food_behavior.
   *
   * @return Return the type behavior of Food
   */
  Behaviors * get_food_behavior() { return food_behavior_; }
  /**
   * @brief Set the behavior for food.
   *
   * @param[in] behavior The new food_behavior.
   */
  void set_food_behavior(Behaviors * behavior) { food_behavior_ = behavior; }
  /**
   * @brief Get the sensor reading from the left sensor.
   * This returns the velocity speed from the left sensor of the Predator
   * respect to an entity.
   *
   * @param[in] entity The entity in the Arean that the left sensor is inspecting.
   *
   * @result Returns a double type of the velocity
   */
  double get_sensor_reading_left(const ArenaEntity* entity);
  /**
   * @brief Get the sensor reading from the right sensor.
   * This returns the velocity speed from the left sensor of the Predator
   * respect to an entity.
   *
   * @param[in] entity The entity in the Arean that the right sensor is inspecting.
   *
   * @result Returns a double type of the velocity
   */
  double get_sensor_reading_right(const ArenaEntity* entity);

  static int count;

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  Behaviors *bv_behavior_;
  Behaviors *light_behavior_;
  Behaviors *food_behavior_;
  const ArenaEntity* closest_bv_entity_;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  const ArenaEntity* closest_pred_entity_;
  double defaultSpeed_;
  int collision_time_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_PREDATOR_VEHICLE_H_
