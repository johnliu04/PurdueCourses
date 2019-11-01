#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.h"

class Circle : public Shape {
public:
   Circle(float);
   ~Circle( );
   double area( );
   double circumference();
   static const double PI=3.141592653589;
private:
   float radius;
};
#endif /* CIRCLE_H_ */
