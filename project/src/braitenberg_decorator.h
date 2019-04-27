/**
 * @file braitenberg_decorator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_DECORATOR_H_
#define SRC_BRAITENBERG_DECORATOR_H_

#include <iostream>
#include <string>

#include "src/braitenberg_vehicle.h"
#include "src/explore.h"
#include "src/none.h"
#include "src/love.h"
#include "src/coward.h"
#include "src/aggressive.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Predator;
class BvDecorator : public BraitenbergVehicle {
 public:
    BvDecorator() {}
    explicit BvDecorator(Predator *predator);

    ~BvDecorator() {}

    /**
    *  @brief Deleting the copy constructor.
    */
    BvDecorator(const BvDecorator & rhs) = delete;
    /**
    *  @brief Deleting the copy assignment.
    */
    BvDecorator operator=(const BvDecorator & rhs) = delete;
    /**
     * @brief Get the name of the underlying arena entity
     *
     * @return Name of the entity.
     */
    std::string get_name() const override;

    EntityType get_PredatorType() {
      return kPredator;
    }

    void TimestepUpdate(__unused unsigned int dt) override;

    Behaviors * getRandomBehavior() {
      // std::cout <<"In Random Behavior" << std::endl;
      int randomNumber = random_num(0, 5);
      Behaviors * newBehavior;
      if (randomNumber == 0) {
        // std::cout <<"In Random Behavior" << std::endl;
        newBehavior = new Aggressive();
      } else if (randomNumber == 1) {
        newBehavior = new Coward();
      } else if (randomNumber == 2) {
        newBehavior = new Explore();
      } else if (randomNumber == 3) {
        newBehavior = new Love();
      } else {
        // std::cout <<"In Random Behavior" << std::endl;
        newBehavior = new None();
      }
      return newBehavior;
    }

 private:
    Predator* predator_{nullptr};
    Behaviors * dynamic_food_behavior_{nullptr};
    Behaviors * dynamic_light_behavior_{nullptr};
    Behaviors * dynamic_bv_behavior_{nullptr};
};

  NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_DECORATOR_H_
