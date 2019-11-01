#include "Rectangle.h"
#include <math.h>
#include <iostream>

Rectangle::Rectangle(float s1, float s2) : Polygon(4, s1), lenSide2(s2) { }

Rectangle::~Rectangle( ) { };

float Rectangle::getArea( ) {
   std::cout << "Rectangle ";
   return lenSides * lenSide2;
}
