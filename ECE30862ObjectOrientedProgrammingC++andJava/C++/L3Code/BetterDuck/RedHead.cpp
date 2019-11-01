#include <iostream>
#include "RedHead.h"

RedHead::RedHead( ) {
   setFlyBehavior(new FlyWithWings( ));
   setQuackBehavior(new QuackQuack( ));
}

RedHead::~RedHead( ) { }

void RedHead::display( ) {
   std::cout << "RedHead duck" << std::endl;
}

