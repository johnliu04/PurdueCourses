#include "Square.h"
#include <math.h>
#include <iostream>

Square::Square(float l) : Polygon(4, l) { }

Square::~Square( ) { };

float Square::getArea( ) {
   std::cout << "Square ";
   return lenSides * lenSides;
}
