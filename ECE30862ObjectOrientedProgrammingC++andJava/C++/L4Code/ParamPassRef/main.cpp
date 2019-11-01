#include <string>
#include <iostream>
using namespace std;
class B {
public:
   B( ); 
   B(int a); 
   virtual void print( ); 
   virtual ~B();
   int age;     
};

B::B( ) {age=-1;}

B::B(int a) {age=a;}

B::~B( ) {cout << "deleting object " << age << endl; };

void B::print( ) {
   cout << "object " << age << endl;
}

class D : public B {
public:
   D(int a, int b); 
   virtual void print( ); 
   virtual ~D();
   int weight;     
};

D::D(int a, int w) : B(a), weight(w)  { } 

D::~D( ) {cout << "deleting object " << age << " " << weight << endl; }

void D::print( ) {cout << "object " << age << " " << weight << endl; }

int main(int argc, char * argv[ ])
{
   B b1(50);
   B b2(150);
   D d1(100, 101);
   D d2(102, 103);
   B& br1 = b1;
   br1.print( );
   br1 = d1;
   br1.print( );
   br1 = b2;
   br1.print( );
   B& br2 = (B&) d2;
   br2.print( );
   br2 = b2;
   br2.print( );
   br2 = d2;
   br2.print( );
   return 0;
}
