// parkingSession class

#include "ParkingSession.h"
ParkingSession::ParkingSession(){

   reservationID=0;
   startHour=0;
   endHour=0;
   occupied=false;
}

void ParkingSession::startSession( int resID, int start){
    reservationID=resID;
    startHour=start;
    occupied=true;
}

void ParkingSession::endSession(int end){
  endHour=end;
  occupied=false;
}

int ParkingSession::getReservationID() const{
  return reservationID;
}

bool ParkingSession::isOccupied() const{
  return occupied;
}

int ParkingSession::getDuration() const {
  int duration=endHour-startHour;

  if (duration<=0)
    duration+=24;
  return duration;
}
