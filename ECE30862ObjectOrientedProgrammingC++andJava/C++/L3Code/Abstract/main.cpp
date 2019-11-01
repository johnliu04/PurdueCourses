#include "Square.h"
#include "Circle.h"
#include <iostream>

int main() {
   Shape* shapes[3]; 
   float totalArea = 0;
   float totalPerim = 0;
   // uncomment for an error.  Shape[0] = new Shape( ); 
   shapes[0] = new Square(4.0); 
   shapes[1] = new Circle(4.0); 
   shapes[2] = new Square(5.0); 

   for (int i = 0; i < 3; i++) {
      totalArea += shapes[i]->area( );
      totalPerim += shapes[i]->circumference( );
   }

   std::cout << "Total Area: " << totalArea;
   std::cout << ", Total Perimeter: " << totalPerim << std::endl;
}
