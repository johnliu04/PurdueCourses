//
// This code is broken because we have only created a copy constructor but
// have not overloaded the "=" operator.
//
#include "X.h"
#include <iostream>

int main(int argc, char * argv[ ]) {
   std::cout << "X x1" << std::endl;
   X x1;
   std::cout << "X x2" << std::endl;
   X x2;
   std::cout << "X x3" << std::endl;
   X x3;
   std::cout << "x2 = x1" << std::endl;
   x2 = x1;
   std::cout << "x3 = x2" << std::endl;
   x3 = x2;
   std::cout << "finished" << std::endl;
}
