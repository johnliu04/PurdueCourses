#ifndef STUDENT_H_
#define STUDENT_H_
#include "Person.h"
#include <string>

class Student : public Person {

public:
   Student(std::string, std::string, std::string);
   virtual ~Student( );

   virtual void codo(std::string);
   virtual std::string getMajor( );

private:
   std::string major;

};
#endif /* STUDENT_H_ */
