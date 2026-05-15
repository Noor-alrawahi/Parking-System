// parkingSession class

#ifndef PARKINGSESSION_H
#define PARKINGSESSION_H
class ParkingSession{
 private:
  int reservationID;
  int startHour;
  int endHour;
  bool occupied;
public:
   ParkingSession();

   void startSession( int resID, int start );
   void endSession(int end);
   int getReservationID() const;
   bool isOccupied() const;
   int getDuration() const;
};

#endif
   
