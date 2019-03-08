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

class factoryFood : public factoryEntity {
	public:
		factoryFood();

		Food * Create(__unused json_object& config) override;
  private:
    int food_count_= 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_FOOD_H_
