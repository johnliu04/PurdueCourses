#include "Base.h"
#include <iostream>

Base::Base( ) { }
Base::~Base( ) { }
void Base::f(double x) {
   std::cout << "Base: " << x << std::endl; 
}
