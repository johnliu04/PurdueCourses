#include "Point.h"
#include <iostream>

Point* Point::rectP = 0; // why not put this into the .h file?
Point* Point::polarP = 0; // why not put this into the .h file?

Point* Point::rectangular(float x, float y) {
   if (rectP == 0) {
      rectP = new Point(x, y);
      return rectP;
   } else return rectP;
}

Point* Point::polar(float radius, float angle) {
   if (polarP == 0) {
      polarP = new Point(radius*std::cos(angle), radius*std::sin(angle));
      return polarP;
   } else return polarP;
}

void Point::printRectangular( ) {
   std::cout << "Rectangular, x: " << rectP-> x_;
   std::cout << ", y: " << rectP->y_ << std::endl; 
}

void Point::printPolar( ) {
   std::cout << "Polar, x: " << polarP-> x_;
   std::cout << ", y: " << polarP->y_ << std::endl; 
}

Point::Point(float x, float y): x_(x), y_(y) { }
