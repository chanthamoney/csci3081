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
#include "src/observer.h"

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

  void set_light_sensors( std::vector<Pose> light_sens) {
    light_sensors_ = light_sens;
  }

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
  /**
   * @brief Register the observer that is observing the braitenberg_vehicle
   *
   * @param[in] o A pointer to an Observer of Wheel velocity pointers
   *
   * @param[out] Setting the observer to the o input
   */
  void RegisterObserver(Observer<std::vector<WheelVelocity*>>* o) {
      observer_ = o;
  }
  /**
   * @brief Unregister the observer that is observing the braitenberg_vehicle
   *  Sets the observer_ to a nullptr
   */
  void UnregisterObserver() {
      observer_ = nullptr;
  }
  /**
   * @brief Notifies the observer of the Wheel Velocity
   *
   * @param[in] arg A pointer to a vector of wheel velocites in the order of light wheel
   * velocity, food wheel velocity, and bv wheel velocity
   *
   */
  void Notify(std::vector<WheelVelocity*>* arg) {
      if (observer_ != nullptr) {
          observer_->UpdateState(arg);
        }
  }
  /**
   * @brief Sets the hungry_time_ of the braitenberg vehicle so it knows when to
   * changes its behavior to go hunt for food because of starvation
   */
  void set_hungry_time(int ht) {
    hungry_time_ = ht;
  }
  /**
   * @brief When a Braitenberg Vehicle starving_time reaches 600 and when a
   * predator touches the braitenberg vehicle it will die
   * The color will become white and opacity will be somewhat transparent
   * The behaviors towards other braitenberg vehicles, food, and light will
   * become noneAdds
   */
  void Die();
  /**
   * @brief When a braitenberg vehicle "collides" with a food entity
   * it consumes the food and it's starving_time_ is set back to 0
   */
  void ConsumeFood();
  /**
   * @brief The count of how many braitenberg vehicle there is. Used to Identify
   * braitenberg vehicles.
   */
  static int count;

  EntityType get_true_type() const { return get_type(); }

  WheelVelocity get_wv() {return wheel_velocity_; }

 private:
   /**
    * @brief A vector for the pose of the light sensor on the braitenberg_vehicle
    */
  std::vector<Pose> light_sensors_;
  /**
   * @brief A pointer to the motion_behavior of the bv
   */
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  /**
   * @brief The wheel velocity of the braitenberg vehicle
   */
  WheelVelocity wheel_velocity_;
  /**
   * @brief A pointer to the robot behavior (bv behavior) of the braitenberg_vehicle
   */
  Behaviors *bv_behavior_;
  /**
   * @brief A pointer to the light behavior of the briatenberg_vehicle
   */
  Behaviors *light_behavior_;
  /**
   * @brief A pointer to the food behavior of the briatenberg_vehicle
   */
  Behaviors *food_behavior_;
  /**
   * @brief The closest braitenberg vehicle entity to the braitenberg vehicle
   */
  const ArenaEntity* closest_bv_entity_;
  /**
   * @brief The closest light entity to the braitenberg vehicle
   */
  const ArenaEntity* closest_light_entity_;
  /**
   * @brief The closest food entity to the braitenberg vehicle
   */
  const ArenaEntity* closest_food_entity_;
  /**
   * @brief The default speed of the braitenberg vehicle
   */
  double defaultSpeed_;
  /**
   * @brief The timestepupdates time after it collides
   */
  int collision_time_ = 0;
  /**
   * @brief The timestepupdate times before it starves at 600
   */
  int starving_time_ = 0;
  /**
   * @brief The default hungry time before the braitenberg_vehicle goes to
   * explore aggressively for food
   */
  int hungry_time_ = 300;
  /**
   * @brief A pointer to an Observer of Wheel velocity pointers
   */
  Observer<std::vector<WheelVelocity*>>* observer_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
