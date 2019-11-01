#ifndef QUACKQUACK_H_
#define QUACKQUACK_H_
#include <string>
#include "QuackBehavior.h"

class QuackQuack : public QuackBehavior {
public:

   QuackQuack( );
   virtual ~QuackQuack( );
   void quackBehavior( );
};
#endif /* QUACKQUACK_H_ */
