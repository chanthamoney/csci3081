/**
 * @file coward.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_COWARD_H_
#define SRC_COWARD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
 * @brief A Coward class for implementing Coward entity behavior
 *
 * The class is used to implement a Coward wheel velocity for
 * entity to entity interactions based on the sensor readings
 */
class Coward : public Behaviors {
 public:
   /**
   *  @brief Coward Constructor.
   */
  Coward() {}
  /**
  *  @brief Coward Deconstructor.
  */
  ~Coward() {}
  /**
  *  @brief getWheelVelocity is the primary purpose for the coward class.
  *  This function changes the WheelVelocity based on the coward behavior
  *
  *  @param[in] left_sensor_reading The left sensor reading of the entity
  *
  *  @param[in] right_sensor_reading The right sensor reading of the entity
  *
  *  @param[in] speed The speed of the entity
  *
  *  @param[out] wheel_velocity The pointer to the new wheel velocity created
  */
  void getWheelVelocity(double left_sensor_reading, double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(left_sensor_reading, right_sensor_reading,
      speed);
  }
  /**
  *  @brief getBehaviorType returns the string of what the behavior type is.
  *
  *  @return The string "Coward"
  */
  std::string getBehaviorType() override {
    return "Coward";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_COWARD_H_
