#ifndef PROTDERIVED_H
#define PROTDERIVED_H
#include <iostream>
#include <string>
#include "Base.h"
using namespace std;

class ProtDerived : protected Base {
public:
	ProtDerived();
	virtual ~ProtDerived();
	void print();
	int getprotB();
	int getprivB();
	int getpublicB();
};

#endif /* PROTDERIVED_H */
