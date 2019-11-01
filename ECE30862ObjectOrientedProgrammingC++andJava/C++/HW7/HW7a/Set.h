#ifndef HW7_SET_H
#define HW7_SET_H

#include <iostream>

class Set{
public:
	Set(int range);
	Set(const Set&);
	virtual ~Set();
	static int count;
	unsigned int* arr;
	int arrsize;
	Set operator+(const int input);
	Set operator-(const int input);
	Set operator/(Set input2);
	Set operator&(Set input2);
	Set operator~();
	int getCopyCount();
};

//print
std::ostream& operator<<(std::ostream& output, const Set& input);

#endif //HW7_SET_H