#ifndef BASE_H_
#define BASE_H_
#include <string>

class Base {
public:
   Base( );
   Base(int);

   virtual ~Base( );

    virtual void print( );
private: 
   int a; 
   int b; 
};
#endif /* BASE_H_ */
