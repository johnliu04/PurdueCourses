#include <iostream>
#include "Base.h"
using namespace std;

Base::Base( ) { }
Base::~Base( ) { }

// include necessary function definitions here
void Base::f1( ){
	std::cout << "Base f1" << std::endl;
}

void Base::f2( ){
	std::cout << "Base f2" << std::endl;
}