/**
 * @file factory_bv.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/entity_type.h"
#include "src/factory_bv.h"
#include "src/params.h"
#include "src/pose.h"
#include "src/rgb_color.h"
#include "src/behavior_enum.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

factoryBraitenberg::factoryBraitenberg() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

BraitenbergVehicle* factoryBraitenberg::Create(__unused json_object* config) {
  BraitenbergVehicle * braitenbergVehicle = new BraitenbergVehicle;
  braitenbergVehicle->LoadFromObject(config);
  return braitenbergVehicle;
}

NAMESPACE_END(csci3081);
