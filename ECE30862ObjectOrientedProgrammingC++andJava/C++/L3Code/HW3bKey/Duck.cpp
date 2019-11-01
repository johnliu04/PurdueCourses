#include <iostream>
#include <string>
#include "Duck.h"

Duck::Duck( ) { 
    flyBehavior = NULL;
    quackBehavior = NULL;
}

Duck::~Duck( ){  }

void Duck::quack( ) {
   if (quackBehavior != NULL) {
      quackBehavior->quack( );
   }
}

void Duck::fly( ) {
   if (flyBehavior != NULL) {
      flyBehavior->fly( );
   }
}

void Duck::setQuackBehavior(QuackBehavior* q) {quackBehavior = q;}

void Duck::setFlyBehavior(FlyBehavior* f) {flyBehavior = f;}

// These maybe should be like quack and fly
void Duck::swim( ) {std::cout << "Swimming!" << std::endl;}

void Duck::display( ) {std::cout << kind << std::endl;}
