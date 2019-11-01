#include "dPublic.h"

dPublic::dPublic( ) { }
dPublic::~dPublic( ){ }
void dPublic::print( ) {
   cout << "dPublic" << endl;
   cout << "privB: " << PublicDerived::getprivB();
   cout << ", protB: " << PublicDerived::getprotB();
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

