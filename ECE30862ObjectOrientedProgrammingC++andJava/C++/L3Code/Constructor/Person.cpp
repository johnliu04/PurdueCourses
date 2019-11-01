#include "Person.h"
#include <string>
#include <iostream>

Person::Person(std::string nm, std::string ad) { 
   name = nm;
   addr = ad;
   std::cout << "Person Constructor" << std::endl;
}

Person::~Person( ){ }

void Person::updateName(std::string nm) {
   name = nm;
}

std::string Person::getName( ) {
   return name;
};

void Person::updateAddr(std::string nm) {
   name = nm;
}

std::string Person::getAddr( ) {
   return name;
};
