// main.cpp
#include <iostream>
#include "Base.h"
#include "D.h"

int f(int i) { std::cout << "fi"; }
int f(double z) { std::cout << "fz"; }
int main(int argc, char* argv[]) {
	C c1; // Q31
	C c2;
	D d; // Q32
	c1.setV(2);
	c1.setSv(4);
	std::cout << "\nc1.v: " << c1.v << " c1.sv: " << c1.sv;
	c2.setV(6);
	c2.setSv(8);
	
	std::cout << "\nc1.v:" << c1.v << " c1.sv: " << c1.sv; // Q33

	std::cout << "\nc2.v:" << c2.v << " c2.sv: " << c2.sv <<"\n"; // Q34
	
	f(1); // Q35
	f(1.0); // Q36
}