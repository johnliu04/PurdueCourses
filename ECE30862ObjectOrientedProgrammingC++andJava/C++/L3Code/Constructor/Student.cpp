#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string nm, string address, string degOption) : 
   Person(nm, address), major(degOption) { 
   std::cout << "Student Constructor" << std::endl;
}

Student::~Student( ) { }

void Student::codo(string newDegree) {
   major = newDegree;
}

string Student::getMajor( ) {
   return major;
}
