/**
 * @file robot_land.cc
 *
 * @copyright 201 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_land.h"
RobotLand::RobotLand(void) {
  for(int i=0; i < num_robots_; i++){
    if(i == 0) {
    robots_[i] = new Robot(i, 50, {512, 350}, 1);
    } //TODO: what is speed?

    else{
      robots_[i] = new Robot(i, 50, {512, 350}, .75);
    }
  }
}

RobotLand::~RobotLand() {
  for(int i=0; i < num_robots_; i++){
    delete robots_[i];
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

 Robot * RobotLand::get_robot(int id) {
   for(int i=0; i<num_robots_; i++){
     if(robots_[i]->get_id() == id){
       return robots_[i];
     }
   }
   return NULL;
 }

// Hard coded for now...
void RobotLand::get_obstacle_pos(double *x_pos, double *y_pos) {
  *x_pos = 200;
  *y_pos = 300;
}
