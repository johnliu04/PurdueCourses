#include "Base.h"
#include "DerivedPriv.h"
#include "DerivedProt.h"
#include "DerivedPublic.h"
#include "DD.h"
#include <iostream>

int main (int argc, char *argv[]) { 
   Base* b = new Base( );
   DerivedPriv* dPriv = new DerivedPriv( );
   DerivedProt* dProt = new DerivedProt( );
   DerivedPublic* dPublic = new DerivedPublic( );
   DD* dd = new DD( );

   std::cout << "base" << std::endl;
   // ERROR std::cout << b->vPriv << std::endl;
   // ERROR std::cout << b->vProt << std::endl;
   std::cout << b->vPublic << std::endl; 

   std::cout << "dPriv" << std::endl;
   // ERROR std::cout << dPriv->vPriv << std::endl;
   // ERROR std::cout << dPriv->vProt << std::endl;
   // ERROR std::cout << dPriv->vPublic << std::endl; 

   std::cout << "dProt" << std::endl;
   // ERROR std::cout << dProt->vPriv << std::endl;
   // ERROR std::cout << dProt->vProt << std::endl;
   // ERROR std::cout << dProt->vPublic << std::endl; 

   std::cout << "dPublic" << std::endl;
   // ERROR std::cout << dPublic->vPriv << std::endl;
   // ERROR std::cout << dPublic->vProt << std::endl;
   std::cout << dPublic->vPublic << std::endl; 

   std::cout << "dd" << std::endl;
   // ERROR std::cout << dd->vPriv << std::endl;
   // ERROR std::cout << dd->vProt << std::endl;
   // ERROR std::cout << dd->vPublic << std::endl; 

   dPriv->printfields( );
   dProt->printfields( );
   dPublic->printfields( );
   dd->printfields( );
}
