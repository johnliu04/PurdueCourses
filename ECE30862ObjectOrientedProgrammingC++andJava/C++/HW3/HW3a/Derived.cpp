#include <iostream>
#include "Base.h"
#include "Derived.h"
using namespace std;

Derived::Derived( ) { }
Derived::~Derived( ) { }

// add necessary functions here
void Derived::f2( )   {
   std::cout << "Derived f2" << std::endl;
}