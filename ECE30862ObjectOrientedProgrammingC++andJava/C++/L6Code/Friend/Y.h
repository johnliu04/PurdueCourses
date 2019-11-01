#ifndef Y_H_
#define Y_H_
#include "X.h"

class X;

class Y {
private:
   X* x;
   int t;
public:
   Y(X* xobj);
   virtual ~Y();
   virtual int get_t( );
};
#endif /* Y_H_ */
