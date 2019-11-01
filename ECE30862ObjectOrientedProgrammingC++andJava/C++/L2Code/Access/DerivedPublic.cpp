#include "DerivedPublic.h"
#include <math.h>
#include <iostream>

DerivedPublic::DerivedPublic( ) { } 
DerivedPublic::~DerivedPublic( ) { } 

void DerivedPublic::printfields( ) {
   std::cout << "DerivedPublic" << std::endl;
   // std::cout << vPriv << std::endl;
   std::cout << vProt << std::endl;
   std::cout << vPublic << std::endl;
}
