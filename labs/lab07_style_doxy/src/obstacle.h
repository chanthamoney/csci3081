/**
 * @file obstacle.h
 *
 * @copyright 2019 3081 Staff and Cassandra Chanthamontry, All rights reserved.
 */


#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

#include <iostream>
#include <utility>

/**
 * @brief The main class for the simulation of a 2D obstacle that robots
 * will interact with.
 *
 *@param[in] The radius of the Obstacle and the position it will start at
 */

class Obstacle {
 public:
  Obstacle() : radius_(10), position_(20.0, 20.0) {}

/**
 * @brief The function to get the radius of the Obstacle
 * @param[out] The radius of the obstacle
 */

  int get_radius() {return radius_;}

/**
 * @brief The function to print out the position of the obstacles
 * @param[out] The x position and y position of the obstacle
 */

  std::pair<double, double> get_pos() {return pos_;}
 private:
  int radius_;
  std::pair<double, double> pos_;
};

#endif  // SRC_OBSTACLE_H_
