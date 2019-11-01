#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

class Set{
public:
	Set(int range);
	Set(const Set&);
	virtual ~Set();
	unsigned long long int sequence;
	int size;
	static int count;
	Set operator + (const int arg);
};

#endif /* SET_H */