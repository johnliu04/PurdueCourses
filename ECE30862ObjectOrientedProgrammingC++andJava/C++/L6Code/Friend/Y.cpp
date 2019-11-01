#include "Y.h"
#include "X.h"

Y::Y(X* xobj) {x = xobj; t = x->m + x->n; }
Y::~Y( ) { }
int Y:: get_t( ) { return t;}
