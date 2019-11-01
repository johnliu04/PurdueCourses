#ifndef Pentagon_H_
#define Pentagon_H_
#include "Polygon.h"
#include <string>

class Pentagon : public Polygon {
public:
   Pentagon(float);
   virtual ~Pentagon( );
   virtual float perimeter( );
};
#endif /*Pentagon_H_*/
