/**
 * @file light_decorator.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "src/light_decorator.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

LightDecorator::LightDecorator(Predator *predator) : predator_(predator) {
       predator_->set_color(LIGHT_COLOR);
       predator->set_radius(LIGHT_RADIUS);
}

/**
 * @brief Get the name of the underlying arena entity
 *
 * @return Name of the entity.
 */
std::string LightDecorator::get_name() const {
  return predator_->get_name();
}

void LightDecorator::TimestepUpdate(__unused unsigned int dt) {
  if (predator_ != NULL) {
    Light::set_pose(predator_->get_pose());
    Light::TimestepUpdate(dt);
    predator_->set_pose(get_pose());
    //
    // Pose pose = predator_->get_pose();
    //
    // // Movement is always along the heading_angle (i.e. the hypotenuse)
    // double new_x =
    //   pose.x + std::cos(pose.theta * M_PI / 180.0) *3;
    // double new_y =
    //   pose.y + std::sin(pose.theta * M_PI / 180.0) *3;
    //
    // /* Heading angle remaings the same */
    // pose.x = new_x;
    // pose.y = new_y;
    // predator_->set_pose(pose);
}
}

NAMESPACE_END(csci3081);
