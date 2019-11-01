#ifndef MALLARD_H_
#define MALLARD_H_
#include "Duck.h"
#include "FlyWithWings.h"
#include "QuackQuack.h"

class Mallard : public Duck {
public:

   Mallard( );
   virtual ~Mallard( );

   void display( );

};
#endif /* MALLARD_H_ */
