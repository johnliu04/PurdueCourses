#include "Base.h"
#include "Derived.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Derived *d = new Derived( );
   d->print( );
}
