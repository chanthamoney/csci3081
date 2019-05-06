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
/**
 * @brief A Food decorator class
 *
 * The class is used to decorate a predator with Food object
 * functionality by wrapping the predator in this decorator
 *
 */
class FoodDecorator : public Food {
 public:
   /**
    * @brief Default constructor.
    */
    FoodDecorator() {}
    /**
     * @brief FoodDecorator's constructor given a pointer to a Predator object
     *
     * @param[in] predator The Predator pointer that is going to be decorated
     *
     */
    explicit FoodDecorator(Predator *predator);
    /**
     * @brief FoodDecorator's destructor. `delete` FoodDecorator created.
     */
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

 private:
  /**
   * @brief A pointer to the predator that is decorated
   */
  Predator* predator_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_DECORATOR_H_
