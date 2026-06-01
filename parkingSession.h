// parkingSession.h

#ifndef PARKINGSESSION_H
#define PARKINGSESSION_H

// ParkingSession Class
// Stores parking session information such as:
// reservation ID, entry time, exit time,
// and whether the slot is currently occupied.

class ParkingSession{
 private:
  int reservationID;
  double startMinutes;
  double endMinutes;
  bool occupied;

public:

// Constructor
   ParkingSession();

// Starts a parking session 
   void startSession( int resID, double start );

// Ends a parking session
   void endSession(double end);

// Returns reservation ID
   int getReservationID() const;

// Returns parking status
   bool isOccupied() const;

// Calculates parking duration
   double getDuration() const;
};

#endif
   
