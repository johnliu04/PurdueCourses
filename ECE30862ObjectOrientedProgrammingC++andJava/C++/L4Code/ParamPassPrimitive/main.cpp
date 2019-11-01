#include <string>
#include <iostream>
using namespace std;
class B {
public:
   B(int);
   virtual ~B();
};

B::B(int k) {
   k += 1;
}

B::~B(){ };
int main(int argc, char * argv[]) {
   int i = 5;
   cout << i << endl;
   B* b = new B(i);
   cout << i << endl;
}
