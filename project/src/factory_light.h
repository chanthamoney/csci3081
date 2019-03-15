/**
 * @file factory_light.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FACTORY_LIGHT_H_
#define SRC_FACTORY_LIGHT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/light.h"
#include "src/factory_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
 *  @brief A factory for the instantiation of the Light arena entity.
 *
 *  The factory takes in a JSON object and creates a Light entity from
 *  the information that the JSON object passed through provides.
 */
class factoryLight : public factoryEntity {
 public:
   /**
   *  @brief factoryLight Constructor.
   */
  factoryLight();
  /**
  *  @brief Create is the primary purpose of this factory.
  *  This function creates the Light from the JSON object.
  *
  *  @param[in] config The pointer to the json_object with the configuration for the Light.
  *
  *  @return A pointer to the Light object that was created.
  */
  Light * Create(json_object* config) override;

 private:
  int light_count_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_LIGHT_H_
