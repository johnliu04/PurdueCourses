#ifndef Triangle_H_
#define Triangle_H_
#include "Polygon.h"
#include <string>

class Triangle : public Polygon {
public:
   Triangle(float);
   virtual ~Triangle( );

   float getArea( );
   virtual float perimeter( );

};
#endif /*Triangle_H_*/
