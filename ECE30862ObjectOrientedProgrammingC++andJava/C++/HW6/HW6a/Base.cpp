#include "Base.h"

int C::sv = 0;
C::C() { std::cout << "ctor C"; }
C::~C() { std::cout << "dtor C"; }
void C::fs() {
	//v = 1.0; // Q29
	sv = -1.0; // Q30
}
void C::setSv(int i) { sv = i; }
void C::setV(int i) { v = i; }