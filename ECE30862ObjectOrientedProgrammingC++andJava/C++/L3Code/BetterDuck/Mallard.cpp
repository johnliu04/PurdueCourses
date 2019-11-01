#include <iostream>
#include "Mallard.h"

Mallard::Mallard( ) { 
   setFlyBehavior(new FlyWithWings( ));
   setQuackBehavior(new QuackQuack( ));
}

Mallard::~Mallard( ) { }

void Mallard::display( ) {
   std::cout << "Mallard duck" << std::endl;
}

