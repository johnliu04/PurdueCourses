#include "B.h"

void f1(B b) {b.age = 10;}
void fr(B& br) {br.age = 100;}

int main(int argc, char * argv[ ])
{
   B b1; // what happens with B b1( );?
   B* bP = &b1;
   B& bR = (B&) b1;
   fr(b1);
   f1(bR);
   bR.print( ); // Comment out this line to remove the error.
   fr(bP);
   return 0;
} 
