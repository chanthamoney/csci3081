#ifndef SRC_POINT_H_
#define SRC_POINT_H_

#include <cstdlib>

struct Point {
public:
  double x_;
  double y_;
  Point(double x=0, double y=0) : x_(x), y_(y) {}
  Point(const Point & pos) {
    x_ = pos.x_;
    y_ = pos.y_;
  }
};

#endif /* SRC_POINT_H_ */
