#ifndef DERIVEDPRIV_H_
#define DERIVEDPRIV_H_
#include "Base.h"

class DerivedPriv : private Base {
public:
   DerivedPriv( );
   virtual ~DerivedPriv( );

    void printfields( );

};
#endif /*DERIVED_H_*/
