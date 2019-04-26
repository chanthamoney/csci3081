#ifndef FOOD_DECORATOR_H_
#define FOOD_DECORATOR_H_

#include <iostream>
#include <string>

#include "src/food.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class FoodDecorator : public Food {
  public:
    FoodDecorator() {}
    FoodDecorator(Predator *predator) : predator_(predator) {
       predator->set_color(FOOD_COLOR);
       predator->set_radius(FOOD_RADIUS);
       // predator->set_mobility(false);
       // predator->set_speed(0);
     }

    ~FoodDecorator() {}

    /**
    *  @brief Deleting the copy constructor.
    */
    FoodDecorator(const FoodDecorator & rhs) = delete;
    /**
    *  @brief Deleting the copy assignment.
    */
    FoodDecorator operator=(const FoodDecorator & rhs) = delete;
    /**
     * @brief Get the name of the underlying arena entity
     *
     * @return Name of the entity.
     */
    std::string get_name() const override { return predator_->get_name(); }

    EntityType get_PredatorType() {
      return kPredator;
    }


 // /**
 //  * @brief Only thing necessary is to update any subscribered sensors
 //  */
 // void TimestepUpdate(__unused unsigned int dt) override {
 //   predator_->setStarvingTime(predator_->getStarvingTime() + 1);
 //   setStarvingTime(predator_->getStarvingTime());
 //   std::cout << getStarvingTime() << std::endl;
 //   Update();
 // }


  private:
  Predator* predator_{nullptr};
  };

  NAMESPACE_END(csci3081);

#endif /* FOOD_DECORATOR_H_ */
