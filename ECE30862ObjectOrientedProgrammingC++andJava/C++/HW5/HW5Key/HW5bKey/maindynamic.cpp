//
// THIS CODE IS EVIL and you should never do anything like this.
// It demonstrates what can go wrong when you use C-style casts
//

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>

int main() {
   Person* p = new Person(1,1,1,"Bob");
   Faculty* f = new Faculty(2,2,2,"Dumbledore");
   Student* s;
   void* v;

   // This is allowed because the dynamic cast will be checked at runtime
   // because the cast is not valid a null pointer will be returned to s, 
   // resulting in a segmentation fault at s->putGPA(6.6) when the pointer
   // is dereferenced.
   s = dynamic_cast<Student*>(f); 
   std::cout << "before (s=f).putGPA(6,6)" << std::endl;
   s->putGPA(6.6);
   std::cout << "before (s=f).getGPA" << std::endl;
   s->getGPA( );

   s = new Student(3,3,3,"Irena");
   f = dynamic_cast<Faculty*>(s); 
   // There is no reason that a Student and Faculty pointer can be assigned to
   // one another since Student not ISA Faculty, and Faculty not ISA Student.
   std::cout << "before (f=s).putSalary" << std::endl;
   f->putSalary(500.0);
   std::cout << "before (f=s).getSalary" << std::endl;
   f->getSalary( );

   // These are an error because the presence of a void pointer means there
   // may not be an object whose type can be checked.
   // v = dynamic_cast<void*>(p);
   // s = dynamic_cast<Student*>(v);
   std::cout << "before (s=p).getGPA" << std::endl;
   s->getGPA( );
   std::cout << "finished" << std::endl;
}
