#ifndef B_H_
#define B_H_

class B {
public:
   B( );
   virtual ~B( ); 
   virtual void print( );
   virtual void print(B b, B* bp, B& br);

   int age;
};
#endif /* _B_H_ */
