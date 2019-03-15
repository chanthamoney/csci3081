/**
 * @file factory_food.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FACTORY_FOOD_H_
#define SRC_FACTORY_FOOD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/food.h"
#include "src/factory_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
 *  @brief A factory for the instantiation of the Food arena entity.
 *
 *  The factory takes in a JSON object and creates a Food entity from
 *  the information that the JSON object passed through provides.
 */
class factoryFood : public factoryEntity {
 public:
   /**
   *  @brief factoryFood Constructor.
   */
  factoryFood();
  /**
  *  @brief Create is the primary purpose of this factory.
  *  This function creates the Food from the JSON object.
  *
  *  @param[in] config The pointer to the json_object with the configuration for the Food.
  *
  *  @return A pointer to the Food object that was created.
  */
  Food * Create(json_object* config) override;
 private:
  int food_count_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_FOOD_H_
