/**
 * @file none.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_NONE_H_
#define SRC_NONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "src/behaviors.h"
#include "src/wheel_velocity.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief An None class for implementing aggressive default behavior
  *
  * The class is used to implement an default wheel velocity for
  * entity to entity interactions based on the sensor readings
  */
class None : public Behaviors {
 public:
   /**
   *  @brief None Constructor.
   */
  None() {}
  /**
  *  @brief None Deconstructor.
  */
  ~None() {}
  /**
  *  @brief getWheelVelocity is the primary purpose for the none class.
  *  This function changes the WheelVelocity based on the none behavior
  *
  *  @param[in] left_sensor_reading The left sensor reading of the entity
  *
  *  @param[in] right_sensor_reading The right sensor reading of the entity
  *
  *  @param[in] speed The speed of the entity
  *
  *  @param[out] wheel_velocity The pointer to the new wheel velocity created
  */
  void getWheelVelocity(__unused double left_sensor_reading,
    __unused double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(0, 0, speed);
  }
  /**
  *  @brief getBehaviorType returns the string of what the behavior type is.
  *
  *  @return The string "None"
  */
  std::string getBehaviorType() override {
    return "None";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_NONE_H_
