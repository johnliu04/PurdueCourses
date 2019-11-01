// No variables that are declared protected or private are accessble in main.
//
// Privates are not accessible because they are only accessible in the classs
// that declares them.
//
// Protected variables are not accessible because they are only accessible in
// the class that declared them or a class that (directly or indirectly) 
// inherits from the class that declared them.  
//
#include <iostream>
#include "Base.h"
#include "D.h"
#include "Q.h"

void foo1(Base& b) {
   b.print( );
}

void foo2(D& d) {
   d.print( );
}

int main(void) {

   Base b;
   D d;
   Base& bR1 = b;
   qs("Q1: Ok:"); Base& bR2 = d; // Q1
   D& dR = d;

   bR1.print( );
   bR2.print( );
   dR.print( );

   qs("Q2: "); bR2.i = 3; // Q2
   qs("Q3: Error"); // ERROR bR2.j = 3; // Q3
   qs("Q4: Ok"); bR1 = bR2; // Q4

   qi(5); std::cout << "bR1.i: " << bR1.i << std::endl; // Q5
   qs("Q6: Error: "); // ERROR std::cout << "bR1.j: " << bR1.j << std::endl; // Q6
   qi(7); std::cout << "bR2.i: " << bR2.i << std::endl; // Q7
   qs("Q8: Error: "); // ERROR std::cout << "bR2.j: " << bR1.j << std::endl; // Q8

   dR.i = 4;
   dR.j = 4;
   qs("Q9: Ok"); bR1 = dR; // Q9
   std::cout << "bR1.i: " << bR1.i << std::endl; // Q10
   qs("Q9: Error"); // ERROR std::cout << "bR1.j: " << bR1.j << std::endl; // Q11
   qi(12); std::cout << "dR.i: " << dR.i << std::endl; // Q12
   qi(12); std::cout << "dR.j: " << dR.j << std::endl; // Q13

   qi(12); foo1(dR); // Q14
   qi(12); foo1(bR1); // Q15
   qs("Q16: Error"); // ERROR foo1(&b); // Q16
   qs("Q17: Error"); // ERROR foo1(&d); // Q17

   foo2(dR); // Q18
   qs("Q19: Error"); // ERROR foo2(bR1); // Q19
   qs("Q20: Error"); // ERROR foo2(&b); // Q20
   qs("Q21: Error"); // ERROR foo2(&d); // Q21
}

