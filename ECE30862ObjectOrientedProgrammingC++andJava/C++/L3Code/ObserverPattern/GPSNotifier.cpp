#include <iostream>
#include"GPSNotifier.h"

GPSNotifier::GPSNotifier(int maxR) { 
   registered = new Observer*[maxR];
   maxRegistered = maxR;
   regIdx = 0;
}

GPSNotifier::GPSNotifier( ) { 
   registered = new Observer*[10];
   maxRegistered = 10;
   regIdx = 0;
}

GPSNotifier::~GPSNotifier( ) {delete registered;}

void GPSNotifier::registerObserver(Observer* obs) { 
   if (regIdx < maxRegistered) {
      registered[regIdx++] = obs;
   } else {
      std::cout << "registered buffer overflow, size is: " << regIdx; 
      std::cout << "max size is: " << maxRegistered << std::endl;
   }
}

void GPSNotifier::removeObserver(Observer* obs) {
   int i = 0;
   while (registered[i] != obs && (i < maxRegistered)) i++;
   if (i < maxRegistered) {
      for (int j = i; j < regIdx; j++) {
         registered[j] = registered[j+1];
      }
      regIdx--;
   } else {
      std::cout << "Observer to be removed not registered. " << std::endl;
   }
}
    
void GPSNotifier::notifyObserver( ) {
   for (int i = 0; i <= regIdx; i++) {
      registered[i]->update( );
   }
}

void GPSNotifier::setState( ) { 
   // call random to simulate getting a new value from the GPS device
   int r = getRandom( );
   if (r-coordinate < 0) r = -r;
   if (r > 10) {
      coordinate = r;
      notifyObserver( );
   }
}
   
int GPSNotifier::getState( ) {return coordinate;}
