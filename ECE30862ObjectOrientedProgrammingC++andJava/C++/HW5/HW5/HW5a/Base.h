#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
using namespace std;

class Base {
private:
   int privB;
protected:
   int protB;
public:
   int publicB;
   Base( );
   virtual ~Base( );
   void print( );
   virtual int getprotB();
   virtual int getprivB();
};

#endif /* BASE_H */
