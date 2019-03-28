/**
 * @file factory_food.cc
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
#include "src/factory_food.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/pose.h"
#include "src/rgb_color.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

factoryFood::factoryFood() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Food* factoryFood::Create(json_object* config) {
  Food * food = new Food;
  food->LoadFromObject(config);
  return food;
}


NAMESPACE_END(csci3081);
