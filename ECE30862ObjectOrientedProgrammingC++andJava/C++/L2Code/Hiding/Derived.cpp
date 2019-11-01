#include "Derived.h"
#include <iostream>

Derived::Derived( ) { }
Derived::~Derived( ) { }
void Derived::f(char x) {
   std::cout << "Derived: " << x << std::endl; 
}
