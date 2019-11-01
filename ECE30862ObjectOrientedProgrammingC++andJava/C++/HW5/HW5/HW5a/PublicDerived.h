#ifndef PUBLICDERIVED_H
#define PUBLICDERIVED_H
#include <iostream>
#include <string>
#include "Base.h"
using namespace std;

class PublicDerived : public Base {
public:
   PublicDerived( );
   virtual ~PublicDerived( );
   void print( );
   int getprotB();
   int getprivB();
};

#endif /* PUBLICDERIVED_H */
