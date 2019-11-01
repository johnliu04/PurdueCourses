#include "X.h"
#include <iostream>
#define UB 1000

X::X( ) {
   ages = new int[UB]; 
   std::cout << "X::X( )" << std::endl;
}

X::X(const X& x) {
   ages = new int[UB]; 
   for (int i=0; i < UB; i++) 
      ages[i] = x.ages[i];
   std::cout << "X::X(const X&)" << std::endl;
}

X::~X( ) {
   std::cout << "~X( )" << std::endl;
   delete ages;
}
