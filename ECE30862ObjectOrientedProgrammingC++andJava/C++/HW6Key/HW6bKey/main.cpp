#include <iostream>
#include "Q.h"
#include "Base.h"
#include "Derived.h"
#include <string>

void foo(Base b) { }
void foo(Derived d) { }
void foo(Base* b) { }
void foo(Derived* d) { }

int main(void) {
   qi(1); Base* bP = new Base( ); // LINE 1
   qi(2); Derived* dP = new Derived( ); // LINE 2
   qi(3); Base b; // LINE 3
   qi(4); Derived d; // LINE 4
   

   qi(5); foo(b); // LINE 5
   qi(6); foo(d); // LINE 6
   qi(7); foo((Base) d); // LINE 7
   qs("Q8: Nothing"); foo(bP); // LINE 8
   qs("Q9: Nothing"); foo(dP); // LINE 9
   qi(10);

} // LINE 10 (what is printed as the program completes?
