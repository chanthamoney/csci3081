#include "src/robot.h"
#include <cmath>
/*UNDERSCORE FOR PRIVATE VARABIELS IN CLASSES*/
Robot::Robot(int id, double radius, Point origin, double speed){
  id_ = id;
  radius_ = radius;
  origin_ = origin;
  speed_ = speed;
  color_ = true;
  position_ = Point(200, 0);
  direction_ = 0;
  sensor_angle_ = 2.0;
  sensor_range_ = 150;
}

void Robot::Update(double t){
  double x = origin_.x_ + 200 * (cos(t*speed_));
  double y = origin_.y_ + 200 * (sin(t*speed_));
  double delta_x = (x - position_.x_)/.1;
  double delta_y = (y - position_.y_)/.1;
  position_ = Point(x, y);
  direction_ = atan2(delta_y, delta_x);
}

bool Robot::get_color(){
  return color_;
}

void Robot::set_color(bool color){
  color_ = color;
}

int Robot::get_id(){
  return id_;
}

double Robot::get_radius(){
  return radius_;
}

Point Robot::get_position(){
  return position_;
}

double Robot::get_direction(){
  return direction_;
}

double Robot::get_sensor_angle(){
  return sensor_angle_;
}

double Robot::get_sensor_range(){
  return sensor_range_;
}
