#include "Base.h"
#include <iostream>

Base::Base(int u, int v, int w) : d(u), c(v), b(w), a(-1) { }

Base::~Base( ) { }

void Base::print( ) {
   std::cout << "a: " << a << ", b: " << b;
   std::cout << ", c: " << c << ", d: " << d << std::endl;
}
