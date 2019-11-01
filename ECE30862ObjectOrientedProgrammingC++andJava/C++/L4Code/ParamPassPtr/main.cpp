#include <string>
#include <iostream>
using namespace std;

class B {
public:
   B(int*);
   virtual ~B();
};

B::B(int* q) {
   *q += 1 ;
}

B::~B(){ }

int main(int argc, char * argv[]) {
   int* p;
   int i = 5;
   p = &i;
   cout << *p << endl;
   B* b = new B(p);
   cout << *p << endl;
}
