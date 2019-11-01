#include <iostream>
#include "Mallard.h"

Mallard::Mallard( ) { 
   setFlyBehavior(new FlyWithWings( ));
   setQuackBehavior(new QuackQuack( ));
}

Mallard::~Mallard( ) { }

void Mallard::display( ) {
   std::cout << "I'm am Mallard duck!" << std::endl;
}
