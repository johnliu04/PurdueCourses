#include "Polygon.h"
#include <math.h>
#include <iostream>

Polygon::Polygon(int n,float l) : 
   numSides(n), lenSides(l) { }

Polygon::Polygon( ) { };
Polygon::~Polygon( ) { };

float Polygon::getArea( ) {
   std::cout << "Poly ";
   float p = numSides*lenSides;
   float apo = numSides / 2. * tan(180. / numSides);
   return apo*p / 2.;
}
