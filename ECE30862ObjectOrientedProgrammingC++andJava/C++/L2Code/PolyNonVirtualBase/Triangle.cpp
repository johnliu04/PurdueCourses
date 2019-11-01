#include "Triangle.h"
#include <math.h>
#include <iostream>

Triangle::Triangle(float l) : Polygon(3, l) { }

Triangle::~Triangle( ) { };

float Triangle::getArea( ) {
   std::cout << "Triangle ";
   return 0.433 * lenSides * lenSides;
}
