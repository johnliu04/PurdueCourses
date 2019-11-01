#include "dProt.h"

dProt::dProt( ) { }
dProt::~dProt( ){ }
void dProt::print( ) { 
   cout << "dProt" << endl;
   cout << "privB: " << ProtDerived::getprivB();
   cout << ", protB: " << ProtDerived::getprotB();
   cout << ", publicB: " << ProtDerived::getpublicB();
   cout << endl << endl;
}

