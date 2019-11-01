#include "Person.h"
#include "Student.h"
#include <iostream>

int main (int argc, char *argv[]) { 

   Student* s = new Student( );
   s->setName("Maria");
   s->setID(1);

   std::cout << "s: " << s->getName( ) << ", " << s->getID( ) << std::endl;

   Person* p = s;
   std::cout << "p: " << p->getName( ) << std::endl;
   /*
    * the following statement is wrong because the Student object is being
    * used as a Person object, and Person does not have a getID function.
    */
   // ERROR std::cout << "p: " << p->getID( ) << std::endl;
}
