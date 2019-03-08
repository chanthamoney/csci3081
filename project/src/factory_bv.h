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

class factoryBraitenberg : public factoryEntity {
	public:
		factoryBraitenberg();

		BraitenbergVehicle* Create(__unused json_object& config) override;

    factoryBraitenberg(const factoryBraitenberg & rhs) = delete;
    factoryBraitenberg operator=(const factoryBraitenberg & rhs) = delete;
  private:
    int vehicle_count_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_BV_H_
