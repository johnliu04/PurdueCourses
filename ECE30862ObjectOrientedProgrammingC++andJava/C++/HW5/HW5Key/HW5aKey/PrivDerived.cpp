#include "PrivDerived.h"

PrivDerived::PrivDerived( ) { }
PrivDerived::~PrivDerived( ){ }
void PrivDerived::print( ) { // NEED TO ADD PrivDerived:: so that c++ knows the
                             // function is the PrivDerived function. 
   cout << "PrivDerived" << endl;
// cout << "privB: " << privB; 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

