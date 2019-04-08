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

class Love : public Behaviors {
 public:
  Love() {}
  ~Love() {}

  void getWheelVelocity(double left_sensor_reading,
    double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(1.0/left_sensor_reading,
      1.0/right_sensor_reading, speed);
  }

  std::string getBehaviorType() override {
    return "Love";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_LOVE_H_
