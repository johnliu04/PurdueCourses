/********************************************************************
 *
 * Abstract class to force implementation of fly( ) in its derived classes
 *
 *********************************************************************/
#ifndef QUACK_H_
#define QUACK_H_

class QuackBehavior {
public:

   QuackBehavior( );
   virtual ~QuackBehavior( );

    virtual void quackBehavior( )=0;
};
#endif /* QUACK_H_ */
