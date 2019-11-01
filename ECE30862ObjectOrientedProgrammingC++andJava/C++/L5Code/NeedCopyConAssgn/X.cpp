#include "X.h"
#include <iostream>

X::X( ) {
   ages = new int[1000]; 
   std::cout << "allocated ages" << std::endl;
}

X::~X( ) {
   delete ages;
   std::cout << "freed ages" << std::endl;
}
