#ifndef GPSNOTIIER_H_
#define GPSNOTIIER_H_
#include "Subject.h"
#include "Observer.h"
class GPSNotifier : public Subject {
public:

   GPSNotifier(int);
   GPSNotifier( );
   virtual ~GPSNotifier( );
   
   virtual void registerObserver(Observer* obs);
   virtual void removeObserver(Observer* obs);
   virtual void notifyObserver( );

   int getState( );
   void setState( );

private:
   int coordinate;
   int getRandom( );

};
#endif /* GPSNOTIFIER_H_ */
