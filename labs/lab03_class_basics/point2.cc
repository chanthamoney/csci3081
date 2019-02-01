#include <iostream>
#include <cmath>
#include "point2.h"

Point2::Point2(double x, double y){
  x_ = x;
  y_ = y;
}

double Point2::DistanceBetween(Point2 obj) {
  double x2 = getX();
  //std::cout << "HERE IS x2" << x2;
  double y2 = getY();
  //std::cout << "HERE IS y2" << y2;
  double x1 = obj.getX();
//  std::cout << "HERE IS x1" << x1;
  double y1 = obj.getY();
  //std::cout << "Here is y1" << y1;
  double x = x2 - x1;
  double y = y2 - y1;
  double distance = sqrt(pow(x, 2.0) + pow(y, 2.0));
  return distance;
}

void Point2::Print() {
  std::cout << "[" << x_ << ",";
  std::cout << y_ <<"]";
}
//TODO: CHECK ONE MORE TIME
int Point2::Quadrant() {
  if (x_ == 0 && y_ == 0){
      return 0;
  }

  if (x_ > 0 && y_ >= 0){
    return 1;
  }

  if (x_ <= 0 && y_ > 0){
    return 2;
  }

  if (x_ < 0 && y_ <= 0){
    return 3;
  }

  if (x_ >= 0 && y_ <0){
    return 4;
  }
  return 0;
}
