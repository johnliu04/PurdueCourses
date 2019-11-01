#ifndef BASE_H_
#define BASE_H_

class Base {
public:
   Base( );
   virtual ~Base( );

   void printfields( );
   int vPublic;

protected:
   int vProt;

private:
   int vPriv;

};
#endif /*BASE_H_*/
