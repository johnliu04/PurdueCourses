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

   // COMPILER ERROR s = static_cast<Student*>(f); 
   // There is no reason that a Student and Faculty pointer can be assigned to
   // one another since Student not ISA Faculty, and Faculty not ISA Student.
   std::cout << "before (s=f).putGPA(6,6)" << std::endl;
   s->putGPA(6.6);
   std::cout << "before (s=f).getGPA" << std::endl;
   s->getGPA( );

   s = new Student(3,3,3,"Irena");
   // COMPILERERROR f = static_cast<Faculty*>(s); 
   // There is no reason that a Student and Faculty pointer can be assigned to
   // one another since Student not ISA Faculty, and Faculty not ISA Student.
   std::cout << "before (f=s).putSalary" << std::endl;
   f->putSalary(500.0);
   std::cout << "before (f=s).getSalary" << std::endl;
   f->getSalary( );

   // These are ok, because it could be Ok to cast a Person pointer to a void,
   // and it could be ok to cast a void pointer to a Student pointer.  
   // The relationship between the first and second cast are not considered.
   v = static_cast<void*>(p);
   s = static_cast<Student*>(v);
   std::cout << "before (s=p).getGPA" << std::endl;
   s->getGPA( );
   std::cout << "finished" << std::endl;
}
