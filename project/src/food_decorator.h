/**
 * @file food_decorator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_FOOD_DECORATOR_H_
#define SRC_FOOD_DECORATOR_H_

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
class Predator;
class FoodDecorator : public Food {
 public:
    FoodDecorator() {}
    explicit FoodDecorator(Predator *predator);

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
    std::string get_name() const override;

    EntityType get_PredatorType() {
      return kPredator;
    }

 private:
  Predator* predator_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_DECORATOR_H_
