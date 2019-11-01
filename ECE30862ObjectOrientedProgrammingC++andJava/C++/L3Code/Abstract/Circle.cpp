#include "Circle.h"
#include <iostream>

Circle::Circle(float r) : radius(r) { }
Circle::~Circle( ) { }
double Circle::area( ) {return Circle::PI*radius*radius;}
double Circle::circumference( ) {return 2*3.14*radius;}
