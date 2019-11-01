#ifndef RUBBER_H_
#define RUBBER_H_
#include "Duck.h"
#include "NoFly.h"
#include "QuackQuack.h"

class Rubber : public Duck {
public:

   Rubber( );
   virtual ~Rubber( );

   void display( );
};
#endif /* RUBBER_H_ */
