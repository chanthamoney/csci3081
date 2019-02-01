//
//  point2.h
//

#ifndef POINT2_H
#define POINT2_H

#include <string>

class Point2 {
public:
   //constructor
  Point2(double x1 = 0.0, double y1 = 0.0);
  //class functions
  double DistanceBetween(Point2 obj);
  void Print();
  int Quadrant();
  //getter function
  double getX(){
    return x;
  }
  double getY(){
    return y;
  }
private:
  double x;
  double y;
};

#endif
