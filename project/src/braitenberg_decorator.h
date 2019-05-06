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
/**
 * @brief A BraitenbergVehicle decorator class
 *
 * The class is used to decorate a predator with BraitenbergVehicle
 * functionality by wrapping the predator in this decorator
 *
 */
class BvDecorator : public BraitenbergVehicle {
 public:
   /**
    * @brief Default constructor.
    */
    BvDecorator() {}
    /**
     * @brief BvDecorator's constructor given a pointer to a Predator object
     *
     * @param[in] predator The Predator pointer that is going to be decorated
     *
     */
    explicit BvDecorator(Predator *predator);
    /**
     * @brief BvDecorator's destructor. `delete` BvDecorators created.
     */
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
    /**
     * @brief Update the decorated Predator position and velocity after the
     * specified duration has passed in order to mimic a BraitenbergVehicle's
     * movement.
     *
     * @param dt The # of timesteps that have elapsed since the last update.
     */
    void TimestepUpdate(__unused unsigned int dt) override;
    /**
     * @brief Get the random behavior for the decorated Predator
     *
     * @return a random Behavior.
     */
    Behaviors * getRandomBehavior();

 private:
    /**
     * @brief A pointer to the predator that is decorated
     */
    Predator* predator_{nullptr};
    /**
     * @brief A pointer to the food behavior of the decorated predator
     */
    Behaviors * dynamic_food_behavior_{nullptr};
    /**
     * @brief A pointer to the light behavior of the decorated predator
     */
    Behaviors * dynamic_light_behavior_{nullptr};
    /**
     * @brief A pointer to the BraitenbergVehicle behavior of the
     * decorated predator
     */
    Behaviors * dynamic_bv_behavior_{nullptr};
};

  NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_DECORATOR_H_
