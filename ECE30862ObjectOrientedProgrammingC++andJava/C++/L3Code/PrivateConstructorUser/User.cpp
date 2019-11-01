#include "User.h"
#include <string>
#include <iostream>

void User::print( ) {
   std::cout << "Name: " << name << ", age: " << age << std::endl;
}
 
User::~User() { }

User::User(std::string nm, int a) : name(nm), age(a) { }
User::User( ) { }
