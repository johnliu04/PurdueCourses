#include "Node.h"
#include "MyClass.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

   Node<int>* headP = new Node<int>(9);
   headP->setPrev(0);
   headP->setNext(0);

   for (int i = 0; i < 5; i++) { 
      Node<int>* tP = new Node<int>(i); 
      tP->setPrev(headP);
      tP->setNext(headP->getNext( ));
      headP->setNext(tP);
   }

   while (headP != 0) {
      std::cout << headP->getData( ) << std::endl;
      headP = headP->getNext( );
   }

   Node<MyClass>* headmP = new Node<MyClass>(MyClass(0,0));
   headmP->setPrev(0);
   headmP->setNext(0);

   for (int i = 1; i < 6; i++) { 
      Node<MyClass>* tP = new Node<MyClass>(MyClass(i,-i), headmP, headmP->getNext( )); 
      // tP->setPrev(headmP);
      // tP->setNext(headmP->getNext( ));
      headmP->setNext(tP);
   }

   while (headmP != 0) {
      std::cout << headmP->getData( ) << std::endl;
      headmP = headmP->getNext( );
   }

   return 0;
}
