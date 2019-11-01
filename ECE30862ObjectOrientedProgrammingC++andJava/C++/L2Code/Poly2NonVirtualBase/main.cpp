#include "Polygon.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Polygon *p = new Square(4.0);
   Rectangle *r = new Square(4.0);

   std::cout << p->getArea( ) << std::endl;
   std::cout << r->getArea( ) << std::endl;

}
