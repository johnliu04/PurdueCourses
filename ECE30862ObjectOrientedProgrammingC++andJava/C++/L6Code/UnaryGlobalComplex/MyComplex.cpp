#include "MyComplex.h"
#include <iostream>
#include <ostream>
using namespace std;

MyComplex::MyComplex(double r, double i) : re(r), im(i) { }

double MyComplex::getReal( ) const {return re; }

double MyComplex::getImag( ) const {return im; }

MyComplex operator+ (const MyComplex& arg1, const MyComplex& arg2) {
   double d1 = arg1.getReal( ) + arg2.getReal( );
   double d2 = arg1.getImag( ) + arg2.getImag( );
   return MyComplex(d1, d2);
}

MyComplex operator-(const MyComplex& arg1, const MyComplex& arg2) {
   double d1 = arg1.getReal( ) - arg2.getReal( );
   double d2 = arg1.getImag( ) - arg2.getImag( );
   return MyComplex(d1, d2);
}

MyComplex operator-(const MyComplex& arg) {
   return MyComplex(-arg.getReal( ), -arg.getImag( ));
}

std::ostream& operator<<(std::ostream& os, const MyComplex& arg) {
   double d1 = arg.getReal( );
   double d2 = arg.getImag( );
   os << "(" << d1 << ", " << d2 << ")" << std::endl;
   return os;
}
