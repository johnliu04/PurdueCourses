#include "B.h"
#include <iostream>
using namespace std;

B::B( ) {age=0; }
B::~B( ) { }

void B::print( ) {cout << age << endl;}

void B::print(B b, B* bp, B& br) {
   cout << "b.age = " << age << ", bp.age = ";
   cout << bp->age << ", br.age = " << br.age << endl;
}
