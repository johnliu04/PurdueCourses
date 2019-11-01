#ifndef X_H_
#define X_H_

#include "Y.h"

class X {
   int m;
   int n;
public:
   X(int mm, int nn);
   friend class Y;
   friend void print(X*);
};
#endif /* X_H_ */
