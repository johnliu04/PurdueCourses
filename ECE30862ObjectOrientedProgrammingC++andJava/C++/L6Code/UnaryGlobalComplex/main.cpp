#include "MyComplex.h"
#include <iostream>

int main( ) {
   MyComplex first(3,4);
   MyComplex second(2,9);
   std::cout << -first;
   std::cout << -second;
   std::cout << first + -second;
   std::cout << first - -second;
   return 0;
}
