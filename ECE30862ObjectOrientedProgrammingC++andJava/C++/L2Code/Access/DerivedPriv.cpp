#include "DerivedPriv.h"
#include <math.h>
#include <iostream>

DerivedPriv::DerivedPriv( ) { }
DerivedPriv::~DerivedPriv( ) { }

void DerivedPriv::printfields( ) {
   std::cout << "DerivedPriv" << std::endl;
   // std::cout << vPriv << std::endl;
   std::cout << vProt << std::endl;
   std::cout << vPublic << std::endl;
}
