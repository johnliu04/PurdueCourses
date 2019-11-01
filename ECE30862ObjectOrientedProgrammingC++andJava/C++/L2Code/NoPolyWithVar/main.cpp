#include "Polygon.h"
#include "Square.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Polygon p(8, 4.0);
   Square s(4.0);
   // Square s2;

   std::cout << p.getArea( ) << std::endl;
   std::cout << s.getArea( ) << std::endl;

   p = s;
   std::cout << p.getArea( ) << std::endl;
   std::cout << s.getArea( ) << std::endl;
}
