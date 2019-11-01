#include "Polygon.h"
#include "Square.h"
#include "Triangle.h"
#include "Pentagon.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Polygon* p[3];
   float area = 0;

   p[0] = new Polygon(8, 4.0);
   p[1] = new Square(4.0);
   p[2] = new Pentagon(4.0);

   p[0]->perimeter( ); 
   p[1]->perimeter( ); 
   p[2]->perimeter( ); 

}
