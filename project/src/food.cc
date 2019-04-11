/**
 * @file food.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/food.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int Food::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Food::Food() : ArenaImmobileEntity() {
  set_type(kFood);
  set_color(FOOD_COLOR);
  set_pose(FOOD_INIT_POS);
  set_radius(FOOD_RADIUS);

  // Set ID
  count++;
  set_id(count);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Food::Reset() {
  set_pose(FOOD_INIT_POS);
} /* Reset */
void Food::Consume() {
  if (food_level_ <= 1) {
    move_to_random_position();
    food_level_ = 50;
    RgbColor color = get_color();
    color.a = 255;
    set_color(color);
  } else {
    food_level_--;
    RgbColor color = get_color();
    color.a = 255 * (static_cast<double>(food_level_) / 50.0);
    set_color(color);
  }
}

NAMESPACE_END(csci3081);
