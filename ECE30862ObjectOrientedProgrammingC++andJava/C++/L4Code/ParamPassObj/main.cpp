#include <string>
#include <iostream>
using namespace std;
class B {
public:
   B(int a); 
   void print( ); 
   ~B();
   int age;
};
 B::B(int a) {
   age=a;
}
void B::print( ) {
   std::cout << age << std::endl;
}

B::~B( ) {std::cout << age << " deleted " << std::endl;};

void foo(B b) {
   b.age = 6;
}
int main(int argc, char * argv[ ])
{
   B b1(5);
   b1.print( );
   foo(b1);
   b1.print( );
   return 0;
}
