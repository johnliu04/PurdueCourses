#include "Base.h"
#include "D1.h"
#include "D2.h"
#include <cstdlib>
#include <iostream>

int main() {
   Base* b;
   D1* d1 = new D1();
   D2* d2 = new D2();
   void* v;

   /***************************************************************/
   /* regular "C-style casts. Don't use these except for numbers. */
   /* They don't correct for                                      */
   /*  the correctness of                                         */
   /***************************************************************/
   b = (Base*) d1;
   b = (Base*) d2;
   d2 = (D2*) b;
   d1 = (D1*) b;
   b = new Base( );
   d1 = (D1*) d2; // compiles, but will cause problems at runtime
   d2 = (D2*) d1; // compiles, but will cause problems at runtime
   v = (void*) b;
   d1 = (D1*) v;  // compiles, but will cause problems at runtime

   /**********************************************************************/
   /* Use static casts when you know the cast is correct.  It does       */
   /* no adjustments to pointers, but does do some compile-time type     */
   /* checking                                                           */
   /**********************************************************************/
   b = static_cast<Base*>(d1);
   b = static_cast<Base*>(d2);
   d2 = static_cast<D2*>(b);
   d1 = static_cast<D1*>(b);
   // compile time ERROR d1 = static_cast<D1*>(d2);
   // compile time ERROR d2 = static_cast<D2*>(d1); 
   v = static_cast<void*>(b);
   d1 = static_cast<D1*>(v);  // compiles, but invalid

   /**********************************************************************/
   /* Use dynamic casts if you are not sure the cast is correct.  It will*/
   /* perform a runtime check on the cast.  If illegal based on compile  */
   /* time info you will get an error.  Appropriately adjusts pointer    */
   /* values where necessary. dynamic_casts should only be used when     */
   /* between pointers to objects as the cast will check the object type */
   /* at runtime                                                         */ 
   /**********************************************************************/
   b = dynamic_cast<Base*>(d1);
   b = dynamic_cast<Base*>(d2);
   d2 = dynamic_cast<D2*>(b);
   d1 = dynamic_cast<D1*>(b);
   d1 = dynamic_cast<D1*>(d2);
   std::cout << "before deref of d1" << std::flush << std::endl;
   float z = d1->i;
   d2 = dynamic_cast<D2*>(d1); 
   std::cout << "before deref of d2" << std::flush << std::endl;
   int k = d2->i;
   std::cout << "after deref of d2" << std::flush << std::endl;
   v = dynamic_cast<void*>(b);
   // COMPILE TIME ERROR d1 = dynamic_cast<D1*>(v);



}
