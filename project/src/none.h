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

class None : public Behaviors {
 public:
  None() {}
  ~None() {}

  void getWheelVelocity(__unused double left_sensor_reading,
    __unused double right_sensor_reading,
    double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(0, 0, speed);
  }

  std::string getBehaviorType() override {
    return "None";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_NONE_H_
