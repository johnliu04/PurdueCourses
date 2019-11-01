#include <iostream>
#include "GPS.h"

GPS::GPS(int s) : x(0.0), y(0.0), size(s), idx(0){
   obs = new Observer*[size];
}

GPS::~GPS( ) {
   delete obs;
}

void GPS::subscribe(Observer* o) {
	if (idx < size) { obs[idx] = o; }
	else { std::cout << "obs full, size: " << size << ", idx: " << idx << std::endl; }
	idx += 1;
}

void GPS::update(double xx, double yy) {
	x = xx;
	y = yy;
	notify();
}

void GPS::notify() {
	for (int i = 0; i < size; i++) {
		obs[i]->notify(x, y);
	}
}