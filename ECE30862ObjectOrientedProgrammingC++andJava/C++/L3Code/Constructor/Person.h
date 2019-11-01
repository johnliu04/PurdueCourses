#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person {
public:
   Person(std::string, std::string);
   virtual ~Person( );

   void updateName(std::string);
   std::string getName( );

   virtual void updateAddr(std::string);
   virtual std::string getAddr( );
private: 
   std::string name;
   std::string addr;

};
#endif /* PERSON_H_ */
