#ifndef LIGHT_DECORATOR_H_
#define LIGHT_DECORATOR_H_

#include <iostream>
#include <string>

#include "src/light.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class LightDecorator : public Light {
  public:
    LightDecorator() {}
    LightDecorator(Predator *predator) : predator_(predator) {
       predator->set_color(LIGHT_COLOR);
       predator->set_radius(LIGHT_RADIUS);
       // predator->set_mobility(false);
       // predator->set_speed(0);
     }

    ~LightDecorator() {}

    /**
    *  @brief Deleting the copy constructor.
    */
    LightDecorator(const LightDecorator & rhs) = delete;
    /**
    *  @brief Deleting the copy assignment.
    */
    LightDecorator operator=(const LightDecorator & rhs) = delete;
    /**
     * @brief Get the name of the underlying arena entity
     *
     * @return Name of the entity.
     */
    std::string get_name() const override { return predator_->get_name(); }

    EntityType get_PredatorType() {
      return kPredator;
    }

    void TimestepUpdate(__unused unsigned int dt) override{
      if (predator_ != NULL) {
        // Light::set_pose(predator_->get_pose());
        // Light::TimestepUpdate(dt);
        // predator_->set_pose(get_pose());

        Pose pose = predator_->get_pose();

        // Movement is always along the heading_angle (i.e. the hypotenuse)
        double new_x =
          pose.x + std::cos(pose.theta * M_PI / 180.0) *3;
        double new_y =
          pose.y + std::sin(pose.theta * M_PI / 180.0) *3;

        /* Heading angle remaings the same */
        pose.x = new_x;
        pose.y = new_y;
        predator_->set_pose(pose);
    }
  }



  private:
  Predator* predator_{nullptr};
  };

  NAMESPACE_END(csci3081);

#endif /* FOOD_DECORATOR_H_ */
