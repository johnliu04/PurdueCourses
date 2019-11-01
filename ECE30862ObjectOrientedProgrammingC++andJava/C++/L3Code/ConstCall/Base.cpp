#include "Base.h"
#include <string>
#include <iostream>

Base::Base( ) {
   a = 40;
   b = 50;
}

Base::Base(int ar) {
   a = 4;
}

Base::~Base( ){ }

void Base::print( ) {
   std::cout << "a: " << a << ", b: " << b << std::endl;
}
