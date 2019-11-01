#ifndef DUCK_H_
#define DUCK_H_
#include <string>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck {
public:

   Duck( );
   virtual ~Duck( );

   virtual void quack( );
   virtual void fly( );
   virtual void swim( );
   virtual void setFlyBehavior(FlyBehavior*);
   virtual void setQuackBehavior(QuackBehavior*);
   virtual void display( )=0;


private:
   FlyBehavior* flyBehavior;
   QuackBehavior* quackBehavior;
};
#endif /* DUCK_H_ */
