#ifndef BASE_H
#define BASE_H

class Base {
private:
   int id;
public:
   static int count;
   Base( );
   // Uncomment this and the definition in Base.cpp to see how 
   // the program works with a copy constructor.
   // Base(const Base&);
   virtual ~Base( );
   virtual void printB( ); // added to the homework program
};

#endif /* BASE_H */
