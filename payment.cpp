// payment class
#include "Payment.h"

Payment::Payment() {
   amount=0;
}

void Payment::calculate( double rate, double duration, bool wrongSlot, bool disabledViolation, bool disabledPermit){
   if (disabledPermit){
     amount=0;
     return ;
   }

   double ratePerMinute=rate/60.0;
   
   amount= ratePerMinute* duration;

   if (wrongSlot)
     amount+=5;

   if (disabledViolation)
     amount+=50;
}
void Payment::display() const {
  cout<<"Total payment: "<< amount<<" OMR\n";
}
