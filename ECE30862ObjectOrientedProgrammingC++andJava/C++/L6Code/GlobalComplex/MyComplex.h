#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_
#include <iostream>

class MyComplex {
   double re, im;

public:
   MyComplex(double r, double i);
   double getReal( ) const;
   double getImag( ) const;
};

MyComplex operator+(const MyComplex&, const MyComplex&);
MyComplex operator-(const MyComplex&, const MyComplex&);
std::ostream& operator<<(std::ostream&, const MyComplex&);

#endif /* MYCOMPLEX */