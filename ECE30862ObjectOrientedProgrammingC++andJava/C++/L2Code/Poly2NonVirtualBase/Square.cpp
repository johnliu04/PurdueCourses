#include "Square.h"
#include <math.h>
#include <iostream>

Square::Square(float l) : Rectangle (l, l) { }

Square::~Square( ) { };

float Square::getArea( ) {
   std::cout << "Square ";
   return lenSides * lenSides;
}
