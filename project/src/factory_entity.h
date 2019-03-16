/**
 * @file factory_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FACTORY_ENTITY_H_
#define SRC_FACTORY_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/common.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
 *  @brief A abstract factory for the instantiation of the arena entities.
 *
 *  The factory takes in a JSON object and creates an arean entity from
 *  the information that the JSON object passed through provides.
 */

class factoryEntity {
 public:
  /**
  *  @brief factoryEntity Deconstructor to 'delete' all factories created.
  */
  virtual ~factoryEntity() {}
  /**
  *  @brief Create is the primary purpose of this factory.
  *  This function creates a new ArenaEntity from the JSON object.
  *
  *  @param[in] config The pointer to the json_object with the configuration for the ArenaEntity.
  *
  *  @return A pointer to the ArenaEntity object that was created.
  */
  virtual ArenaEntity* Create(json_object* config) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_ENTITY_H_
