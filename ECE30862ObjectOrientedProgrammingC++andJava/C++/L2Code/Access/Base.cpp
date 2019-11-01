#include "Base.h"
#include <math.h>
#include <iostream>

Base::Base( ) { 
   vPriv = 0;
   vProt = 1;
   vPublic = 2;
};

Base::~Base( ) { };

void Base::printfields( ) {
   std::cout << "base" << std::endl;
   std::cout << vPriv << std::endl;
   std::cout << vProt << std::endl;
   std::cout << vPublic << std::endl;
}
