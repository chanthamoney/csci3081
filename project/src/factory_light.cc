/**
 * @file factory_light.cc
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
 #include "src/factory_light.h"



/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

factoryLight::factoryLight(){}; //TODO: Constructor What should I do..

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

 Light* factoryLight::Create(){ //create entity here
   return new Light;
 };


NAMESPACE_END(csci3081);
