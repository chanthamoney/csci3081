/**
 * @file aggressive.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_AGGRESSIVE_H_
#define SRC_AGGRESSIVE_H_

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
 * @brief An aggressive class for implementing aggressive entity behavior
 *
 * The class is used to implement an aggressive wheel velocity for
 * entity to entity interactions based on the sensor readings
 */
class Aggressive : public Behaviors {
 public:
   /**
   *  @brief Aggressive Constructor.
   */
  Aggressive() {}
  /**
  *  @brief Aggressive Deconstructor.
  */
  ~Aggressive() {}
  /**
  *  @brief getWheelVelocity is the primary purpose for the Aggressive class.
  *  This function changes the WheelVelocity based on the aggressive behavior
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
    *wheel_velocity = WheelVelocity(right_sensor_reading, left_sensor_reading,
      speed);
  }
  /**
  *  @brief getBehaviorType returns the string of what the behavior type is.
  *
  *  @return The string "Aggressive"
  */
  std::string getBehaviorType() override {
    return "Aggressive";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_AGGRESSIVE_H_
