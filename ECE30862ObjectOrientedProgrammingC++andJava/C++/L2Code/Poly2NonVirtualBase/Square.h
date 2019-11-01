#ifndef Square_H_
#define Square_H_
#include "Rectangle.h"
#include <string>

class Square : public Rectangle {
public:
   Square(float);
   virtual ~Square( );

   float getArea( );

};
#endif /*Square_H_*/
