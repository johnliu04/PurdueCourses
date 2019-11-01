#include "PrivDerived.h"

PrivDerived::PrivDerived() { }
PrivDerived::~PrivDerived() { }
void PrivDerived::print() {
	cout << "PrivDerived" << endl;
	cout << "privB: " << Base::getprivB();
	cout << ", protB: " << protB;
	cout << ", publicB: " << publicB;
	cout << endl << endl;
}

int PrivDerived::getprotB() {
	return Base::getprotB();
}

int PrivDerived::getprivB() {
	return Base::getprivB();
}

int PrivDerived::getpublicB() {
	return publicB;
}