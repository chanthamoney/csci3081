/**
 * @file braitenberg_vehicle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_VEHICLE_H_
#define SRC_BRAITENBERG_VEHICLE_H_

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
 * @brief Entity class to represent a BraitenbergVehicle.
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class BraitenbergVehicle : public ArenaMobileEntity {
 public:
  /**
   * @brief Default constructor.
   */
  BraitenbergVehicle();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  /**
  *  @brief Deleting the copy constructor.
  */
  BraitenbergVehicle(const BraitenbergVehicle & rhs) = delete;
  /**
  *  @brief Deleting the copy assignment.
  */
  BraitenbergVehicle operator=(const BraitenbergVehicle & rhs) = delete;

  /**
   * @brief Update the BraitenbergVehicle's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;
  /**
   * @brief Update the BraitenbergVehicle's wheel velocity based on the
   * behaviors set by light_behavior_ and food_behavior_
   *
   */
  void Update() override;

  /**
   * @brief Change the movement state of the BraitenbergVehicle.
   * When a collision occurs, the BraitenbergVehicle will turn 180 degrees,
   * move 20 timesteps, and then turn the heading 45 degrees (turn left).
   *
   * @param[in] ent_type The type of ArenaEntity the BraitenbergVehicle collided with
   * @param[in] object ArenaEntity object that the BraitenbergVehicle collided with
   *
   */
  void HandleCollision(EntityType ent_type,
                       ArenaEntity * object = NULL) override;

 /**
  * @brief Senses or Identify, the entity that are in the range of the BraitenbergVehicle's
  * sensor. Then this will update the closest_entity (either food or light).
  *
  * @param[in] entity The AreanEntity that is sense by the BraitenbergVehicle.
  */
  void SenseEntity(const ArenaEntity& entity);
  /**
   * @brief Get the name of the BraitenbergVehicle.
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
   * To match the direction that the BraitenbergVehicle is facing.
   *
   */
  void UpdateLightSensors();
  /**
   * @brief Takes in json_object and gets the configuration from the object.
   * The configuration from the object consist of the Type of entity (BraitenbergVehicle),
   * light_behavior, food_behavior, radius, x, y, and theta position.
   *
   * @param[in] entity_config The json_object pointer to the configuration that for the BraitenbergVehicle
   */
  void LoadFromObject(json_object* entity_config) override;
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
   * This returns the velocity speed from the left sensor of the BraitenbergVehicle
   * respect to an entity.
   *
   * @param[in] entity The entity in the Arean that the left sensor is inspecting.
   *
   * @result Returns a double type of the velocity
   */
  double get_sensor_reading_left(const ArenaEntity* entity);
  /**
   * @brief Get the sensor reading from the right sensor.
   * This returns the velocity speed from the left sensor of the BraitenbergVehicle
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
  Behaviors *light_behavior_;
  Behaviors *food_behavior_;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  double defaultSpeed_;
  int collision_time_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
