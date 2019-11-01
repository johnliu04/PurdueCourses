#ifndef BASE_H_
#define BASE_H_
#include <string>

class Base {
public:
   Base(int,int,int);

   virtual ~Base( );

   virtual void print( );
   int a;
   int b;
private: 
   int c; 
   int d; 
};
#endif /* BASE_H_ */
