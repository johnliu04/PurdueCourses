#include "Point.h"

int main (int argc, char *argv[]) { 

   Point* rP = Point::rectangular(10.0,20.0);
   Point::printRectangular( );
   rP = Point::rectangular(30.0,40.0);
   Point::printRectangular( );
}
