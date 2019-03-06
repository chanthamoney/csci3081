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
    //THIS IS INTERFACE
class factoryEntity{
	public:
    virtual ~factoryEntity() {}
    virtual ArenaEntity* Create() = 0; //TODO: Add json later can be empty for unit test

};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_ENTITY_H_
