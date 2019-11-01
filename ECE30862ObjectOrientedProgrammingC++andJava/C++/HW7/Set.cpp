#include "Set.h"
#include <string>
using namespace std;

int Set::count = 0;

Set::Set(int range) :size(range + 1), sequence(0) { }
Set::Set(const Set& arg) {
	Set::count++;
	memcpy(this, &arg, sizeof(Set));
}
Set::~Set() { }


Set Set::operator + (const int arg) {
	unsigned long long int mask = 1 << arg;
	if ((mask & sequence) == mask) {
		return *this;
	}
	sequence = sequence | mask;
	return *this;
}