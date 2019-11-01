#include "X.h"
#include <iostream>

X::X(int sz) : size(sz) {
   ages = new int[sz]; 
   std::cout << "X::X( )" << std::endl;
}

X::X(const X& x) {
   ages = new int[x.size]; 
   for (int i=0; i < x.size; i++) 
      ages[i] = x.ages[i];
   std::cout << "X::X(const X&)" << std::endl;
}

X::~X( ) {
   std::cout << "~X( )" << std::endl;
   delete ages;
}

X& X::operator=(const X& x) {
   if (this != &x) {
      delete [ ] ages;
      ages = new int[x.size];
      for (int i; i < x.size; i++) 
         ages[i] = x.ages[i];
   }
   std::cout << "X::operator=" << std::endl;
   return *this;
}
