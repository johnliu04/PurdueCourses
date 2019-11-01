#include <iostream>
#include "Rubber.h"
#include "NoFly.h"
#include "QuackQuack.h"

Rubber::Rubber( ) {
   setFlyBehavior(new NoFly( ));
   setQuackBehavior(new QuackQuack( ));
}

Rubber::~Rubber( ) { }

void Rubber::display( ) {
   std::cout << "I'm a rubber duck!" << std::endl; 
}
