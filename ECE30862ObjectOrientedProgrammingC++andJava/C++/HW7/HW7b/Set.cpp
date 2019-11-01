#include <string>
#include "Set.h"
using namespace std;

int Set::count = 1;

Set::Set(int range) {
	int size = range / 32;
	if (range % 32) {
		size += 1;
	}
	arrsize = range;
	arr = (unsigned int*)malloc(sizeof(unsigned int) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = 0x00000000;
	}
}
Set::~Set() { }

Set::Set(const Set& arg) {
	Set::count++;
	memcpy(this, &arg, sizeof(Set));
}

Set operator+(Set input, const int value) {
	int index = value / 32;
	int size = value % 32;
	unsigned long long int mask = 0x00000001 << size;
	input.arr[index] = input.arr[index] | mask;
	return input;
}

Set operator-(Set input, const int value) {
	int index = value / 32;
	int size = value % 32;
	unsigned long long int mask = 0x00000001 << size;
	input.arr[index] = input.arr[index] & ~(mask);
	return input;
}

Set operator/(Set input1, Set input2) {
	Set output(input1.arrsize);
	int size;
	unsigned int list;
	if (input1.arrsize >= input2.arrsize) {
		size = input1.arrsize / 32;
		if (input1.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input1.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & !(input2.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	else {
		size = input2.arrsize / 32;
		if (input2.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input2.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & !(input1.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	return output;
}

Set operator&(Set input1, Set input2) {
	Set output(input1.arrsize);
	int size;
	unsigned int list;
	if (input1.arrsize >= input2.arrsize){
		size = input1.arrsize / 32;
		if (input1.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input1.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & (input2.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	else {
		size = input2.arrsize / 32;
		if (input2.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input2.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & (input1.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	return output;
}

Set operator~(Set input) {
	int size = input.arrsize / 32;
	if (input.arrsize % 32) {
		size += 1;
	}
	for (int index = 0; index < size; index++) {
		input.arr[index] = ~(input.arr[index] & 0xffffffff);
	}
	return input;
}

int Set::getCopyCount() {
	return Set::count;
}

//output
std::ostream& operator<<(std::ostream& output, const Set& intput) {
	bool comma = 0;
	unsigned int list;
	int size = intput.arrsize / 32;
	if (intput.arrsize % 32) {
		size += 1;
	}
	for (int index = 0; index < size; index++) {
		list = intput.arr[index];
		for (int i = 0; i < 32; i++) {
			if (list >> i & 1) {
				if (comma) { output << ", "; }
				output << i + 32 * index;
				comma = 1;
			}
		}
	}
	output << '\n';
	return output;
}