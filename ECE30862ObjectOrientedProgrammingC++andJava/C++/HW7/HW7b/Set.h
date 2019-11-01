#ifndef HW7_SET_H
#define HW7_SET_H

#include <iostream>

class Set {
public:
	Set(int range);
	Set(const Set&);
	virtual ~Set();
	static int count;
	unsigned int* arr;
	int arrsize;
	int getCopyCount();
};

Set operator+(Set input, const int value);
Set operator-(Set input, const int value);
Set operator/(Set input1, Set input2);
Set operator&(Set input1, Set input2);
Set operator~(Set input);

//print
std::ostream& operator<<(std::ostream& output, const Set& input);

#endif //HW7_SET_H