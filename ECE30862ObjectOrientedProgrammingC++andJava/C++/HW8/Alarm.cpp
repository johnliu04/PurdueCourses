#include <iostream>
#include <cmath>
#include "Alarm.h"

Alarm::Alarm(Subject * s, int i, double xx, double yy, double alarm) 
	: id(i), x(xx), y(yy), soundAlarm(alarm){  
	//Subscribe to subject s using s’s subscribe function.
	s->subscribe(this);
}

Alarm::~Alarm( ) { }

void Alarm::notify(double xx, double yy) {
	double lenth = (xx - x) * (xx - x) + (yy - y) * (yy - y);
	if (std::sqrt(lenth) > soundAlarm) {
		std::cout << "Alarm" << id << " Sounded! Moved " << std::sqrt(lenth) << " meters" << std::endl;
	}
}