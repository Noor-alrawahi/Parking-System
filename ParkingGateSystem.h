#ifndef PARKINGGATESYSTEM_H
#define PARKINGGATESYSTEM_H

#include <vector>

#include "Customer.h"
#include "ParkingSlot.h"
#include "Reservation.h"
#include "ParkingSession.h"
#include "Payment.h"

using namespace std;

const int MAX_CUSTOMERS = 20;
const int MAX_RESERVATIONS = 20;
const int MAX_SESSIONS = 20;

class ParkingGateSystem {
private:
  vector<ParkingSlot*>slot;

  Customer customers[MAX_CUSTOMERS];
  Reservation reservations[MAX_RESERVATIONS];
  parkingSession sessions[MAX_SESSIONS];

  int customerCount;
  int reservationCount;
  int sessionCount;

  Customer* findCustomer(int id);

  Reservation* findReservation(
      int reservationID
  );

  ParkingSession* findSession(
      int ReservationID
  );

public:
  ParkingGateSystem();

  ~ParkingGateSystem();

  int getOccupiedCount() const;

  int getAvailableCount() const;

  void registerCustomer();

  void showSlots();

  void reserveSlot();

  void enterGate();

  void exitGate();
};

#endif
