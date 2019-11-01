#include "Y.h"
#include "X.h"
#include <iostream>

void print(X* ptr) {std::cout << ptr->m << " " << ptr->n << std::endl;} 

int main( )
{
   X* ptr = new X(100, 200);
   Y y(ptr);
   std::cout << y.get_t( ) << std::endl;
   print(ptr);
   return 0;
}

