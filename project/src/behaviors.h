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

class Behaviors {
 public:
  virtual ~Behaviors() {}
  virtual void getWheelVelocity(double left_sensor_reading,
    double right_sensor_reading, double speed,
    WheelVelocity *wheel_velocity) = 0;
  virtual std::string getBehaviorType() = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIORS_H_
