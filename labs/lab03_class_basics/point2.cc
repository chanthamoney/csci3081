#include <iostream>
#include <cmath>
#include "point2.h"

Point2::Point2(double x1, double y1){
  x = x1;
  y = y1;
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
  std::cout << x;
  std::cout << y;
}
//TODO: CHECK ONE MORE TIME
int Point2::Quadrant() {
  if (x == 0 && y == 0){
      return 0;
  }

  if (x > 0 && y >= 0){
    return 1;
  }

  if (x <= 0 && y > 0){
    return 2;
  }

  if (x < 0 && y <= 0){
    return 3;
  }

  if (x >= 0 && y <0){
    return 4;
  }
  return 0;
}
