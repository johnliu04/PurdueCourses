#ifndef DERIVEDPROT_H_
#define DERIVEDPROT_H_
#include "Base.h"

class DerivedProt : protected Base {
public:
   DerivedProt( );
   virtual ~DerivedProt( );

   void printfields( );

};
#endif /*DERIVEDPROT_H_*/
