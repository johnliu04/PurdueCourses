#ifndef DERIVEDPUBLIC_H_
#define DERIVEDPUBLIC_H_
#include "Base.h"
#include <string>

class DerivedPublic : public Base {
public:
   DerivedPublic( );
   virtual ~DerivedPublic( );

   void printfields( );
};
#endif /*DERIVEDPUBLIC_H_*/
