/**
 * @file factory_bv.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FACTORY_PREDATOR_H_
#define SRC_FACTORY_PREDATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/predator.h"
#include "src/factory_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
 *  @brief A factory for the instantiation of the PredatorVehicle arena entity.
 *
 *  The factory takes in a JSON object and creates a Predator Vehicle entity from
 *  the information that the JSON object passed through provides.
 */
class factoryPredator : public factoryEntity {
 public:
   /**
   *  @brief factoryPredator Constructor.
   */
  factoryPredator();
  /**
  *  @brief Create is the primary purpose of this factory.
  *  This function creates the Predator Vehicle from the JSON object.
  *
  *  @param[in] config The pointer to the json_object with the configuration for the Predator vehicle.
  *
  *  @return A pointer to the PredatorVehicle object that was created.
  */
  Predator* Create(json_object* config) override;
  /**
  *  @brief Deleting the copy constructor.
  */
  factoryPredator(const factoryPredator & rhs) = delete;
  /**
  *  @brief Deleting the copy assignment.
  */
  factoryPredator operator=(const factoryPredator & rhs) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_PREDATOR_H_
