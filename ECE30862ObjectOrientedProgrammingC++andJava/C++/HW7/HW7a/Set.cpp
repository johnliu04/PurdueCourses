#include "Set.h"
#include <string>
#include <cstring>
using namespace std;

int Set::count = 1;

Set::Set(int range){
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
Set::~Set() {}

Set::Set(const Set& arg) {
	Set::count++;
	memcpy(this, &arg, sizeof(Set));
}

Set Set::operator+(const int input){
	int index = input / 32;
	int size = input % 32;
	unsigned long long int mask = 0x00000001 << size;
	arr[index] = arr[index] | mask;
	return *this;
}

Set Set::operator-(const int input) {
	int index = input / 32;
	int size = input % 32;
	unsigned long long int mask = 0x00000001 << size;
	arr[index] = arr[index] & ~(mask);
	return *this;
}

Set Set::operator/(Set input2) {
	Set output(arrsize);
	unsigned int list;
	int size;
	if (arrsize >= input2.arrsize){
		size = arrsize / 32;
		if (arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & !(input2.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	else{
		size = input2.arrsize / 32;
		if (input2.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input2.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & !(arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	return output;
}

Set Set::operator&(Set input2) {
	Set output(arrsize);
	unsigned int list;
	int size;
	if (arrsize >= input2.arrsize){
		size = arrsize / 32;
		if (arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & (input2.arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	else{
		size = input2.arrsize / 32;
		if (input2.arrsize % 32) {
			size += 1;
		}
		for (int index = 0; index < size; index++) {
			list = input2.arr[index];
			for (int i = 0; i < 32; i++) {
				if ((list >> i & 1) & (arr[index] >> i & 1)) {
					output.arr[index] = output.arr[index] | (0x00000001 << (i % 32));
				}
			}
		}
	}
	return output;
}

Set Set::operator~() {
	int size = arrsize / 32;
	if (arrsize % 32) {
		size += 1;
	}
	for (int index = 0; index < size; index++) {
		arr[index] = ~(arr[index] & 0xffffffff);
	}
	return *this;
}

int Set::getCopyCount() {
	return Set::count;
}

//output
std::ostream& operator<<(std::ostream& output, const Set& intput){
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