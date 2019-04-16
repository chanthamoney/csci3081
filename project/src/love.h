/**
 * @file love.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_LOVE_H_
#define SRC_LOVE_H_

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
  * @brief A love class for implementing love entity behavior
  *
  * The class is used to implement a love wheel velocity for
  * entity to entity interactions based on the sensor readings
  */
class Love : public Behaviors {
 public:
   /**
   *  @brief Love Constructor.
   */
  Love() {}
  /**
  *  @brief Love Deconstructor.
  */
  ~Love() {}
  /**
  *  @brief getWheelVelocity is the primary purpose for the love class.
  *  This function changes the WheelVelocity based on the love behavior
  *
  *  @param[in] left_sensor_reading The left sensor reading of the entity
  *
  *  @param[in] right_sensor_reading The right sensor reading of the entity
  *
  *  @param[in] speed The speed of the entity
  *
  *  @param[out] wheel_velocity The pointer to the new wheel velocity created
  */
  void getWheelVelocity(double left_sensor_reading,
    double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(1.0/left_sensor_reading,
      1.0/right_sensor_reading, speed);
  }
  /**
  *  @brief getBehaviorType returns the string of what the behavior type is.
  *
  *  @return The string "Love"
  */
  std::string getBehaviorType() override {
    return "Love";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_LOVE_H_
