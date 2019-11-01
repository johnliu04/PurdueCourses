#include "DerivedProt.h"
#include <math.h>
#include <iostream>

DerivedProt::DerivedProt( ) { } 
DerivedProt::~DerivedProt( ) { } 

void DerivedProt::printfields( ) {
   std::cout << "DerivedProt" << std::endl;
   // std::cout << vPriv << std::endl;
   std::cout << vProt << std::endl;
   std::cout << vPublic << std::endl;
}
