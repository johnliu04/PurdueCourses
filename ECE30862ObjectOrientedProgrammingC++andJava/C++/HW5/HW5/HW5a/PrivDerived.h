#ifndef PRIVDERIVED_H
#define PRIVDERIVED_H
#include "Base.h"
#include <iostream>
#include <string>
using namespace std;

class PrivDerived : private Base {
public:
	PrivDerived();
	virtual ~PrivDerived();
	void print();
	virtual int getprotB();
	virtual int getprivB();
	virtual int getpublicB();
};

#endif /* PRIVDERIVED_H */
