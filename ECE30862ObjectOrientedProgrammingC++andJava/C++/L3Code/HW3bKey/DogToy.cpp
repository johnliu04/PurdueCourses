#include <iostream>
#include "DogToy.h"

DogToy::DogToy( ) {
   setFlyBehavior(new NoFly( ));
   setQuackBehavior(new Squeak( ));
}

DogToy::~DogToy( ) { }

void DogToy::display( ) {
   std::cout << "I'm a dog toy duck!" << std::endl;
}

