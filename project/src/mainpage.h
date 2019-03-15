/**
 * @file mainpage.h
  * @copyright 2017 3081 Staff and Cassandra Chanthamontry, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage Project: Iteration 1
 *
 * \section intro_sec Introduction to Iteration 1
 *
 * Iteration 1 for the project was to stimulate the behavior of Braitenberg Vehicles. This project uses a graphic window
 * to stimulate how the Braitenberg vehicle exhibit aggression, fear, exploration and love towards two stimuli: Food and Light.
 * In this iteration, I implemented a Factory pattern to create entities such as Food, Light, and Braitenberg Vehicle.
 * When the Braitenberg vehicle sensors being stimulated by Food it will turn blue, with Light it will turn Gold, or when
 * the Braitenberg vehicle is stimulated by both or none it will become blue.
 * Another feature added was the collision handling. This was implemented in order for the  Braitenberg vehicle not to get stuck.
 * When the Braitenberg vehicle collidies to a wall, it will turn around 180 degrees and head in that direction for a short time
 * which is 20 timesteps, then it will turn left (45 degrees).
 */

#endif  //  SRC_MAINPAGE_H_
