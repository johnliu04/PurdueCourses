#include "Pentagon.h"
#include <math.h>

Pentagon::Pentagon(float l) : Polygon(5, l)  { }
Pentagon::~Pentagon( ) { }
float Pentagon::perimeter( ) {return 5*lenSides;}
