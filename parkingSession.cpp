// parkingSession.cpp

#include "ParkingSession.h"

// Constructor
// Initializes default values

ParkingSession::ParkingSession(){

   reservationID=0;
   startMinutes=0.0;
   endMinutes=0.0;
   occupied=false;
}

// startSession()
// Saves reservation ID and entry time

void ParkingSession::startSession( int resID, double start){
    reservationID=resID;
    startMinutes=start;

   // Vehicle is now parked 
    occupied=true;
}

// endSession()
// Saves exit time and free slots

void ParkingSession::endSession(double end){
  endMinutes=end;

   // Vehicle has exited
  occupied=false;
}

// Returns reservation ID

int ParkingSession::getReservationID() const{
  return reservationID;
}

// Returns occupancy status

bool ParkingSession::isOccupied() const{
  return occupied;
}

// getDuration()
// Calculates parking duration in minutes
// Handles overnight parking
// Example:
// Start= 11:00 PM
// End= 1:00 AM

double ParkingSession::getDuration() const {

   // Total minutes in one day 
  double minutesInDay=24.0*60.0; 

   //Calculate duration 
  double duration=endMinutes-startMinutes;

   // If negative, add one full day 
  if (duration<=0)
    duration +=  minutesInDay;
  return duration;
}
