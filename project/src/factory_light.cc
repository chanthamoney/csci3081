/**
 * @file factory_light.cc
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
#include "src/factory_light.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

factoryLight::factoryLight() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Light* factoryLight::Create(__unused json_object* config) {
  Light * light = new Light;
  light->LoadFromObject(config);
  return light;
}

NAMESPACE_END(csci3081);
