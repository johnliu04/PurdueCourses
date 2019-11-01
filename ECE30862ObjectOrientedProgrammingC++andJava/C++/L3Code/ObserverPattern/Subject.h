#ifndef SUBJECT_H_
#define SUBJECT_H_
#include "Observer.h"

class Subject {
public:
   virtual void registerObserver( ) = 0;
   virtual void removeObserver( ) = 0;
   virtual void notifyObserver( ) = 0;

protected:
   // Using a Standard Template Library hashmap to hold the registered items would be better,
   // but we haven't covered that so I'm using a simple array of pointers to the registered 
   // objects.
   Observer** registered;
   int regIdx; 
   int maxRegistered;
};
#endif /* SUBJECT_H_ */
