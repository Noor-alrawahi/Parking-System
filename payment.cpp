// payment class
#include "Payment.h"

Payment::Payment() {
   amount=0;
}

void Payment::calculate( double rate, int duration, bool wrongSlot, bool disabledViolation, bool disabledPermit){
   if (disabledPermit){
     amount=0;
     return ;
   }
   amount= rate* duration;

   if (wrongSlot)
     amount+=5;

   if (disabledViolation)
     amount+=50;
}
void Payment::display() const {
  cout<<"Total payment: "<< amount<<" OMR\n";
}
