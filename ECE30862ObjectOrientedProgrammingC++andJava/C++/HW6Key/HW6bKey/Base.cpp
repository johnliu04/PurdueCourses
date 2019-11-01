#include <iostream>
#include "Base.h"

int Base::count=0;

Base::Base( ) {
  id = count++;
  std::cout << "C B: " << id << std::endl;
}

// Uncomment this code to see how things work with a copy constructor
// Also uncomment the declaration in Base.h
// Base::Base(const Base& bIn) {
//    id = count++;
//    std::cout << "cC B: " << id << std::endl;
// }

Base::~Base( ) {std::cout << "~Base: " << id << std::endl;}

void Base::printB( ) {std::cout << "id is: " << id << ", count is: " << count << std::endl;}
