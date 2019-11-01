#include "X.h"
#include <iostream>

int main(int argc, char * argv[ ]) {
   X xStack;  

   std::cout << "before new" << std::endl;
   X *xHeap = new X( );

   std::cout << "delete xHeap" << std::endl;
   delete xHeap;
   std::cout << "delete xHeap finished" << std::endl;
   
   return 0;
}
