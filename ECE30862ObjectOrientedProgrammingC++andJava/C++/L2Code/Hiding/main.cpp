#include "Base.h"
#include "Derived.h"

int main() {
   Derived* d = new Derived();
   Base* b = d;
   b->f(65.3); // okay: passes 65.3 to f(double x)
   d->f(65.3); // converts 65.3 to a char ('A' if ASCII) and passes it 
               // to f(char c); It does NOT call f(double x);

}
