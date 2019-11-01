#ifndef USER_H_
#define USER_H_
#include <string>
class User {
public:
   virtual void print( ); 
   virtual ~User();
private: 
   User(std::string nm, int a); 
   User( );
   std::string name; 
   int age; 
};
#endif /* USER_H_ */
