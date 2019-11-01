#include "Square.h"
#include <math.h>
#include <iostream>

Square::Square(float l) : Polygon(4, l) { 
   polyName = "Square";
}

Square::~Square( ) { };

float Square::getArea( ) {
   std::cout << "Square ";
   return lenSides * lenSides;
}

float Square::perimeter( ) {
   return 4*lenSides;
}

void Square::printName( ) {
   std::cout << polyName << std::endl;
}
