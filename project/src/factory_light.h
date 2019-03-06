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

class factoryLight : public factoryEntity {
	public:
		factoryLight();

		Light * Create() override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_LIGHT_H_
