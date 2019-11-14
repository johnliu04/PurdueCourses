#include "MyComplex.h"
#include <iostream>
#include <ostream>
using namespace std;

MyComplex::MyComplex(double r, double i) : re(r), im(i) { }

double MyComplex::getReal( ) const {return re; }

double MyComplex::getImag( ) const {return im; }

MyComplex MyComplex::operator+ (const MyComplex& rightOp) {
   double d1 = getReal( ) + rightOp.getReal( );
   double d2 = getImag( ) + rightOp.getImag( );
   return MyComplex(d1, d2);
}

MyComplex MyComplex::operator-(const MyComplex& rightOp) {
   double d1 = getReal( ) - rightOp.getReal( );
   double d2 = getImag( ) - rightOp.getImag( );
   return MyComplex(d1, d2);
}

std::ostream& operator<<(std::ostream& os, const MyComplex& arg) {
   double d1 = arg.getReal( );
   double d2 = arg.getImag( );
   os << "(" << d1 << ", " << d2 << ")" << std::endl;
   return os;
}