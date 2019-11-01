#ifndef NOQUACK_H_
#define NOQUACK_H_
#include <string>
#include "QuackBehavior.h"

class NoQuack : public QuackBehavior {
public:

   NoQuack( );
   virtual ~NoQuack( );
   void quackBehavior( );
};
#endif /* NOQUACK_H_ */
