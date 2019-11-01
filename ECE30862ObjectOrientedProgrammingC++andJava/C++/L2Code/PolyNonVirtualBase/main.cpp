#include "Polygon.h"
#include "Square.h"
#include "Triangle.h"
#include "Pentagon.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Polygon* p[2];
   float area = 0;

   p[0] = new Polygon(8, 4.0);
   p[1] = new Square(4.0);

   std::cout << p[0]->getArea( ) << std::endl;
   std::cout << p[1]->getArea( ) << std::endl;

}
