#include "Student.h"
#include <iostream>

int main( ) {
   Student s1("John");
   Student s2("Amy");
   std::cout << (s1 < s2) << std::endl;  // false
   std::cout << (s2 < s1) << std::endl;  // true
   std::cout << (s2 < s2) << std::endl;  // false
   std::cout << (s2 > s1) << std::endl;  // false
   std::cout << (s1 < s2) << std::endl;  // true
   std::cout << (s2 == s2) << std::endl; // true
   return 0;
}
