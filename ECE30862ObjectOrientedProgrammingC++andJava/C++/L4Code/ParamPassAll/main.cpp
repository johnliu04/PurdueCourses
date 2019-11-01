#include "B.h"
#include <iostream>

void f1(B b) {b.age = 10;}

void fp(B* bp) {bp->age = 1000;}

void fr(B& br) {br.age = 100;}

int main(int argc, char * argv[ ])
{
   B b1; 
// what happens with B b1( );?
   B* bP = &b1;
   B& bR = (B&) b1;
   f1(b1);
   std::cout << "after f1 call " << std::endl;
   b1.print(b1, bP, bR);
   fr(bR);
   std::cout << "after fr call " << std::endl << std::endl;
   b1.print(b1, bP, bR);
   fp(bP);
   std::cout << "after fp call " << std::endl << std::endl;
   b1.print(b1, bP, bR);
   return 0;
}
