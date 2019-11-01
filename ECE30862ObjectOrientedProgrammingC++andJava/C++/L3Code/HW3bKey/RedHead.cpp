#include <iostream>
#include "RedHead.h"

RedHead::RedHead( ) {
   setFlyBehavior(new FlyWithWings( ));
   setQuackBehavior(new QuackQuack( ));
}

RedHead::~RedHead( ) { }

void RedHead::display( ) {
   std::cout << "I'm a redhead duck!" << std::endl;
}
