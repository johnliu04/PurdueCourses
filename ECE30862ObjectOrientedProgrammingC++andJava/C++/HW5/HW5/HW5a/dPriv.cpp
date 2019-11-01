#include "dPriv.h"

dPriv::dPriv( ) { }
dPriv::~dPriv( ){ }
void dPriv::print( ) { 
   cout << "dPriv" << endl;
   cout << "privB: " << PrivDerived::getprivB();
   cout << ", protB: " << PrivDerived::getprotB();
   cout << ", publicB: " << PrivDerived::getpublicB();
   cout << endl << endl;
}

