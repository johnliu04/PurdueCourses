#include <iostream>
#include "Rubber.h"

Rubber::Rubber( ) { 
   setFlyBehavior(new NoFly( ));
   setQuackBehavior(new QuackQuack( ));
}

Rubber::~Rubber( ) { }

void Rubber::display( ) {
   std::cout << "Rubber duck" << std::endl;
}

