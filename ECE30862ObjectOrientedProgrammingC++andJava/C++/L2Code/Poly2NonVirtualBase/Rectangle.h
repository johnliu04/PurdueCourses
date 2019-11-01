#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Polygon.h"
#include <string>

class Rectangle : public Polygon {
public:
   Rectangle(float, float);
   virtual ~Rectangle( );

   virtual float getArea( );

private:
   float lenSide2;

};
#endif /*RECTANGLE_H_*/
