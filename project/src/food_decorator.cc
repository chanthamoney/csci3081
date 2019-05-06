/**
 * @file food_decorator.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/food_decorator.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
FoodDecorator::FoodDecorator(Predator *predator) : predator_(predator) {
       predator_->set_color(FOOD_COLOR);
       predator->set_radius(FOOD_RADIUS);
}

std::string FoodDecorator::get_name() const { return predator_->get_name(); }

NAMESPACE_END(csci3081);
