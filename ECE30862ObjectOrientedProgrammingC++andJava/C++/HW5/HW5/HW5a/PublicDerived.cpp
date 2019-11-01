#include "PublicDerived.h"

PublicDerived::PublicDerived( ) { }
PublicDerived::~PublicDerived( ){ }
void PublicDerived::print( ) { 
   cout << "publicDerived" << endl;
   cout << "privB: " << Base::getprivB();
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

int PublicDerived::getprotB() {
	return Base::getprotB();
}

int PublicDerived::getprivB() {
	return Base::getprivB();
}