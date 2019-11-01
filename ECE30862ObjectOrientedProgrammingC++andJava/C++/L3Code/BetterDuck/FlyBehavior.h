/********************************************************************
 *
 * Abstract class to force implementation of fly( ) in its derived classes
 *
 *********************************************************************/
#ifndef FLYBEHAVIOR_H_
#define FLYBEHAVIOR_H_
#include <string>

class FlyBehavior {
public:

   FlyBehavior( );
   virtual ~FlyBehavior( );
   virtual void flyBehavior( )=0;
};
#endif /* FLYBEHAVIOR_H_ */
