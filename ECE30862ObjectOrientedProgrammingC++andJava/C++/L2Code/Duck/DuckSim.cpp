#include <iostream>
#include "Duck.h"
#include "Mallard.h"
#include "RedHead.h"

int main (int argc, char *argv[]) { 

    Duck* ducks[4];

    ducks[0] = new Mallard( );
    ducks[1] = new RedHead( );
    ducks[2] = new Mallard( );
    ducks[3] = new Duck( );

    for (int i = 0; i < 4; i++) {
       ducks[i]->display( );
       ducks[i]->quack( );
       ducks[i]->fly( );
       std::cout << std::endl;
   }
}
