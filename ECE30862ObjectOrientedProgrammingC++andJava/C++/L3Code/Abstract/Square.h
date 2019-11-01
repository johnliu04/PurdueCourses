#ifndef SQUARE_H_
#define SQUARE_H_
#include "Shape.h"

class Square : public Shape {
public:
   Square(float);
   ~Square( );
   double area( );
   double circumference();
private:
   float side;
};
#endif /* SQUARE_H_ */
