#include "X.h"
#include <iostream>

void f(X x) { }

int main(int argc, char * argv[ ]) {
   X x1;
   f(x1);
   f(x1);
}
