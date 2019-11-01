#include "Base.h"
#include <iostream>

Base::Base(int u, int v, int w) : d(8), c(b), b(4), a(d) { }

Base::~Base( ) { }

void Base::print( ) {
   std::cout << "a: " << a << ", b: " << b;
   std::cout << "c: " << c << ", d: " << d;
}
