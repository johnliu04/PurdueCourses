/********************************************************************
 *
 * This is a kludge for the time being because we don't yet know 
 * about abstract classes.  But it will work for now.  The only
 * purpose of this class is for other classes to inherit from it
 * and to therefore support polymorphic behavior.
 *
 *********************************************************************/
#ifndef QUACKBEHAVIOR_H_
#define QUACKBEHAVIOR_H_
#include <string>

class QuackBehavior {
public:

   QuackBehavior( );
   virtual ~QuackBehavior( );
   virtual void quack( )=0;
};
#endif /* QUACKBEHAVIOR_H_ */
