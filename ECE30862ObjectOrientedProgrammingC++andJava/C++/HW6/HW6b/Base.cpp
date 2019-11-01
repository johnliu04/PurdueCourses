#include <iostream>
#include "Base.h"

int Base::count=0;

Base::Base( ) {
  idb = count++;
  std::cout << "C B: " << idb << std::endl;
}

Base::~Base( ) {std::cout << "~Base: " << idb << std::endl;}
