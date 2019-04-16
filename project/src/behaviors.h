/**
 * @file behavior.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BEHAVIORS_H_
#define SRC_BEHAVIORS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An abstract behavior class for implementing entity to entity behavior
 *
 * The class is used to implement wheel velocity based on behavior and
 * sensor reading for entity to entity interactions
 *
 */
class Behaviors {
 public:
   /**
   *  @brief Behaviors Deconstructor.
   */
  virtual ~Behaviors() {}
  /**
  *  @brief getWheelVelocity is the primary purpose for the Behavior class.
  *  This function changes the WheelVelocity based on the behavior
  *
  *  @param[in] left_sensor_reading The left sensor reading of the entity
  *
  *  @param[in] right_sensor_reading The right sensor reading of the entity
  *
  *  @param[in] speed The speed of the entity
  *
  *  @param[out] wheel_velocity The pointer to the new wheel velocity created
  */
  virtual void getWheelVelocity(double left_sensor_reading,
    double right_sensor_reading, double speed,
    WheelVelocity *wheel_velocity) = 0;
  /**
  *  @brief getBehaviorType returns the string of what the behavior type is.
  *
  *  @return The string of what the behavior is
  */
  virtual std::string getBehaviorType() = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIORS_H_
