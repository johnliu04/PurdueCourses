#include <iostream>
#include <string>
#include "Duck.h"

Duck::Duck( ) : quackBehavior(NULL), flyBehavior(NULL) { }

Duck::~Duck( ) { }

void Duck::quack( ) {
   if (quackBehavior != NULL) {
      quackBehavior->quackBehavior( );
   }
}

void Duck::fly( ) {
   if (flyBehavior != NULL) {
      flyBehavior->flyBehavior( );
   }
}

void Duck::setQuackBehavior(QuackBehavior* q) {quackBehavior = q;}

void Duck::setFlyBehavior(FlyBehavior* f) {flyBehavior = f;}

void Duck::swim( ) {std::cout << "Swimming!" << std::endl;}
