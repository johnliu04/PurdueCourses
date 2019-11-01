#ifndef DUCK_H_
#define DUCK_H_
#include <string>

class Duck {
public:

   Duck(std::string);
   Duck( );
   virtual ~Duck( );

   virtual void quack( );
   virtual void fly( );
   virtual void swim( );
   virtual void display( );

private:
   std::string kind;
};
#endif /* DUCK_H_ */
