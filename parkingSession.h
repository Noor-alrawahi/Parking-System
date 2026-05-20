// parkingSession class

#ifndef PARKINGSESSION_H
#define PARKINGSESSION_H
class ParkingSession{
 private:
  int reservationID;
  double startMinutes;
  double endMinutes;
  bool occupied;

public:
   ParkingSession();

   void startSession( int resID, double start );
   void endSession(double end);
   int getReservationID() const;
   bool isOccupied() const;
   double getDuration() const;
};

#endif
   
