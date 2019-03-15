/**
 * @file factory_bv.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FACTORY_BV_H_
#define SRC_FACTORY_BV_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/braitenberg_vehicle.h"
#include "src/factory_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
 *  @brief A factory for the instantiation of the BraitenbergVehicle arena entity.
 *
 *  The factory takes in a JSON object and creates a Braitenberg Vehicle entity from
 *  the information that the JSON object passed through provides.
 */
class factoryBraitenberg : public factoryEntity {
 public:
   /**
   *  @brief factoryBraitenberg Constructor.
   */
  factoryBraitenberg();
  /**
  *  @brief Create is the primary purpose of this factory.
  *  This function creates the Braitenberg Vehicle from the JSON object.
  *
  *  @param[in] config The pointer to the json_object with the configuration for the Braitenberg vehicle.
  *
  *  @return A pointer to the BraitenbergVehicle object that was created.
  */
  BraitenbergVehicle* Create(json_object* config) override;
  /**
  *  @brief Deleting the copy constructor.
  */
  factoryBraitenberg(const factoryBraitenberg & rhs) = delete;
  /**
  *  @brief Deleting the copy assignment.
  */
  factoryBraitenberg operator=(const factoryBraitenberg & rhs) = delete;

};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_BV_H_
