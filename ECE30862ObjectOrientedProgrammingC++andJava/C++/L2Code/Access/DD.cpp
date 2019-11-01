#include "DD.h"
#include <math.h>
#include <iostream>

DD::DD( ) { } 
DD::~DD( ) { } 

void DD::printfields( ) {
   std::cout << "DD" << std::endl;
   // std::cout << vPriv << std::endl;
   std::cout << vProt << std::endl;
   std::cout << vPublic << std::endl;
}
