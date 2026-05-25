// Payment.cpp

#include "Payment.h"

// Constructor that initializes the amount to zero 

Payment::Payment() {
   amount=0;
}

// calculate()
// Calculates parking payment
// rate = hourly parking rate
// duration = parking duration in minutes
// wrongslot =  parked in wrongslot
// disabledViolation = used disabled slot illegally
// disabledPermit = disabled customer free parking

void Payment::calculate( double rate, double duration, bool wrongSlot, bool disabledViolation, bool disabledPermit){

   // Disabled customers park for free
   if (disabledPermit){
     amount=0;
     return ;
   }
   
   double ratePerMinute=rate/60.0;

   // Basic parking cost
   amount= ratePerMinute* duration;

   // Add wrong slot penalty
   if (wrongSlot)
     amount+=5;

   // Add disabled parking violation penalty
   if (disabledViolation)
     amount+=50;
}
void Payment::display() const {
  cout<<"Total payment: "<< amount<<" OMR\n";
}
