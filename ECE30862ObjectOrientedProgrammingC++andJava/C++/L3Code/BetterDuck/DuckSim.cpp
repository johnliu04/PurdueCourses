#include <iostream>
#include "Duck.h"
#include "Mallard.h"
#include "RedHead.h"
#include "DogToy.h"
#include "Rubber.h"
#include "Dog.h"

int main (int argc, char *argv[]) { 

   Duck* ducks[ ] = {new Mallard( ), new RedHead( ),
                      new Rubber( ), new DogToy( )};
   Dog* dog = new Dog( );

   for (int i = 0; i < 4; i++) {
      ducks[i]->display( );
      ducks[i]->quack( );
      ducks[i]->fly( );
      std::cout << std::endl;
   }

   for (int i = 2; i < 3; i++) {
      dog->play(ducks[3]);
      ducks[3]->display( );
      ducks[3]->quack( );
      ducks[3]->fly( );
   }
}
