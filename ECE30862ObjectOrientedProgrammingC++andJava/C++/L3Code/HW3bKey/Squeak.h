#ifndef SQUEAK_H_
#define SQUEAK_H_
#include <string>
#include "QuackBehavior.h"

class Squeak : public QuackBehavior {
public:

   Squeak( );
   virtual ~Squeak( );
   void quack( );
};
#endif /* SQUEAK_H_ */
