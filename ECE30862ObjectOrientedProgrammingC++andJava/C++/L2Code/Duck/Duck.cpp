#include <iostream>
#include <string>
#include "Duck.h"

Duck::Duck( ) {
    kind = "generic duck";
}

Duck::Duck(std::string k) {
    kind = k;
}

Duck::~Duck( ){ }

void Duck::quack( ) {std::cout << "quack" << std::endl;}

void Duck::fly( ) {std::cout << "fly" << std::endl;}

void Duck::swim( ) {std::cout << "swim" << std::endl;}

void Duck::display( ) {std::cout << kind << std::endl;}
