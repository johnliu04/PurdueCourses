#include "B.h"
#include <iostream>

void fr(const B& br) {
   B* b = &br;
   br.age = 100;
}

int main(int argc, char * argv[ ]) {
   B b1; 
   B* bP = &b1;
   B& bR = (B&) b1;
   fr(bR);
   return 0;
}
