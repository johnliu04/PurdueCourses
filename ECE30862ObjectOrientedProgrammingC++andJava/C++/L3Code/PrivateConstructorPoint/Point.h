#ifndef POINT_H_
#define POINT_H_
#include <cmath>        // To get std::sin() and std::cos()

class Point {
public:
  static Point* rectangular(float x, float y);   
  Point* polar(float radius, float angle);
  static void printRectangular( );
  static void printPolar( );

private:
  Point(float x, float y);   // Rectangular coordinates
  float x_, y_;
  static Point* rectP; // these have been added to the class definition
  static Point* polarP; 
};
#endif /* POINT_H_ */
