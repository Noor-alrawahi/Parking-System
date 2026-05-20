// parkingSession class

#include "ParkingSession.h"

ParkingSession::ParkingSession(){

   reservationID=0;
   startMinutes=0.0;
   endMinutes=0.0;
   occupied=false;
}

void ParkingSession::startSession( int resID, double start){
    reservationID=resID;
    startMinutes=start;
    occupied=true;
}

void ParkingSession::endSession(double end){
  endMinutes=end;
  occupied=false;
}

int ParkingSession::getReservationID() const{
  return reservationID;
}

bool ParkingSession::isOccupied() const{
  return occupied;
}

double ParkingSession::getDuration() const {
  double minutesInDay=24.0*60.0; 
  double duration=endMinutes-startMinutes;

  if (duration<=0)
    duration +=  minutesInDay;
  return duration;
}
