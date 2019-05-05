/**
 * @file light_decorator.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_LIGHT_DECORATOR_H_
#define SRC_LIGHT_DECORATOR_H_

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
class Predator;
/**
 * @brief A Light decorator class
 *
 * The class is used to decorate a predator with Light object
 * functionality by wrapping the predator in this decorator
 */
class LightDecorator : public Light {
 public:
   /**
    * @brief Default constructor.
    */
    LightDecorator() {}
    /**
     * @brief LightDecorator's constructor given a pointer to a Predator object
     *
     * @param[in] predator The Predator pointer that is going to be decorated
     *
     */
    explicit LightDecorator(Predator *predator);
    /**
     * @brief LightDecorator's destructor. `delete` LightDecorators created.
     */
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
    std::string get_name() const override;

    /**
     * @brief Update the decorated Predator position and velocity after the specified
     * duration has passed in order to mimic a Light's movement
     *
     * @param dt The # of timesteps that have elapsed since the last update.
     */
    void TimestepUpdate(__unused unsigned int dt) override;

 private:
  /**
   * @brief A pointer to the predator that is decorated
   */
  Predator* predator_{nullptr};
};

  NAMESPACE_END(csci3081);

#endif  // SRC_LIGHT_DECORATOR_H_
