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

class Aggressive : public Behaviors {
 public:
  Aggressive() {}
  ~Aggressive() {}

  void getWheelVelocity(double left_sensor_reading, double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(right_sensor_reading, left_sensor_reading,
      speed);
  }

  std::string getBehaviorType() override {
    return "Aggressive";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_AGGRESSIVE_H_
