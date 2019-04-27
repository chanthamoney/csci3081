/**
 * @file food.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/arena_immobile_entity.h"
#include "src/common.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a immobile food within the Arena.
 *
 * Food can enhance a Robot. If a Robot touches the Food, it becomes
 * a super robot.
 *
 * Food have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class Food : public ArenaImmobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A food_params passed down from main.cc for the
   * initialization of the Food.
   */
  Food();

  /**
   * @brief Reset the Food using the initialization parameters received
   * by the constructor.
   */
  void Reset() override;

  /**
   * @brief Only thing necessary is to update any subscribered sensors
   */
  void TimestepUpdate(__unused unsigned int dt) override {
    std::cout << "HELP ME GOD" << std::endl;
    Update();
  }
  /**
   * @brief Get the percentage of how much food is left in the food entity
   */
  int get_food_level() {
    return static_cast<int>((static_cast<float>(food_level_) / 50.0)*100);
  }
  /**
   * @brief When the braitenberg vehicle entity touches a food entity,
   * the food enetiy gets consumed and loses some of it's food level
   */
  void Consume();

  /**
   * @brief Get the name of the Food for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Food.
   */
  std::string get_name() const override { return "Food"; }
  /**
   * @brief The count of how many food entity there is. Used to Identify
   * food entities.
   */
  static int count;

  EntityType get_true_type() const { return get_type(); }


 private:
   /**
    * @brief The level of food the food entity has. When it reaches 0 it will
    * disappear and respwan in the arena
    */
  int food_level_ = 50;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_H_
