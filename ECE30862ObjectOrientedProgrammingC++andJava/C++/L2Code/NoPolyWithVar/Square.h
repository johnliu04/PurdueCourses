#ifndef Square_H_
#define Square_H_
#include "Polygon.h"
#include <string>

class Square : public Polygon {
public:
   Square(float);
   virtual ~Square( );

   float getArea( );
   virtual float perimeter( );
   virtual void printName( );

private:
   std::string polyName;

};
#endif /*Square_H_*/
