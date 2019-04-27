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
class LightDecorator : public Light {
 public:
    LightDecorator() {}
    explicit LightDecorator(Predator *predator);
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

    EntityType get_PredatorType() {
      return kPredator;
    }

    void TimestepUpdate(__unused unsigned int dt) override;

 private:
  Predator* predator_{nullptr};
};

  NAMESPACE_END(csci3081);

#endif  // SRC_LIGHT_DECORATOR_H_
