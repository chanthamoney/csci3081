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

#include "wheel_velocity.h"
#include "behaviors.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Coward : public Behaviors {
 public:
  Coward() {}
  ~Coward() {}

  void getWheelVelocity (double left_sensor_reading, double right_sensor_reading, double speed, WheelVelocity *wheel_velocity) override {
    *wheel_velocity = WheelVelocity(left_sensor_reading, right_sensor_reading, speed);
  }

  std::string getBehaviorType() override {
    return "Coward";
  }
};

NAMESPACE_END(csci3081);

#endif  // SRC_COWARD_H_
