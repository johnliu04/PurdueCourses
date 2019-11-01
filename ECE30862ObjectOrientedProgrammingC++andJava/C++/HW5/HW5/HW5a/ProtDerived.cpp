#include "ProtDerived.h"

ProtDerived::ProtDerived() { }
ProtDerived::~ProtDerived() { }
void ProtDerived::print() {
	cout << "ProtDerived" << endl;
	cout << "privB: " << Base::getprivB();
	cout << ", protB: " << protB;
	cout << ", publicB: " << publicB;
	cout << endl << endl;
}

int ProtDerived::getprotB() {
	return Base::getprotB();
}

int ProtDerived::getprivB() {
	return Base::getprivB();
}

int ProtDerived::getpublicB() {
	return publicB;
}
