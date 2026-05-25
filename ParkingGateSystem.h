#ifndef PARKINGGATESYSTEM_H
#define PARKINGGATESYSTEM_H

#include <vector>

#include "Customer.h"                    // header files for all class used in the system
#include "SunnySlot.h"
#include "ShadedSlot.h"
#include "ParkingSlot.h"
#include "Reservation.h"
#include "ParkingSession.h"
#include "Payment.h"

using namespace std;

const int MAX_CUSTOMERS = 20;           // maximum limit for arrays
const int MAX_RESERVATIONS = 20;
const int MAX_SESSIONS = 20;

class ParkingGateSystem {                                // main class that manages the parking gate system
private:
  vector<ParkingSlot*>slots;                             // vector to store all parking slot objects

  Customer customers[MAX_CUSTOMERS];                     // arrays to store info
  Reservation reservations[MAX_RESERVATIONS];
  ParkingSession sessions[MAX_SESSIONS];

  int customerCount;                                    // counters to track number of stored objects
  int reservationCount;
  int sessionCount;

  Customer* findCustomer(int id);                           //finds a customer uding customer id
  Reservation* findReservation(int reservationID);          // finds a reservation using reservation id
  ParkingSession* findSession(int reservationID);           // finds a parking session using reservation id 
  static double getOmanTimeMinutes();                       // gets current oman time in minutes
public: 
  ParkingGateSystem();                                      // constructor 
  ~ParkingGateSystem();                                     // destructor

  int getOccupiedCount() const;
  int getAvailableCount() const;

  void registerCustomer();
  void showSlots();
  void reserveSlot();
  void enterGate();
  void exitGate();
};

#endif
