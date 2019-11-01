#ifndef BASE_H
#define BASE_H
#include <iostream>
// C.h
class C {
public:
	int v;
	static int sv;
	C();
	virtual ~C();
	static void fs();
	virtual void setSv(int);
	virtual void setV(int);
};

#endif /* BASE_H */
