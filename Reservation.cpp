#include "Reservation.h"

Reservation::Reservation() {   //default constructor initializes empty reservation 

reservationID = 0;
customerID = 0;
reservedSlot = 0;
actualSlot = 0;
wrongSlot = false;
active = false;
}

Reservation::Reservation(     //parameterized constructor initializes reservation data
int resID,
int custID,
int slot
) {

reservationID = resID;
customerID = custID;
reservedSlot = slot;
actualSlot = 0;
wrongSlot = false;
active = true;
}

int Reservation::getReservationID() const {
  return reservationID;
}

int Reservation::getCustomerID() const {
  return customerID;
}

int Reservation::getActualSlot() const {
  return actualSlot;
}

int Reservation::getReservedSlot() const {
  return reservedSlot;
}

bool Reservation::hasWrongSlot() const {
  return wrongSlot;
}

bool Reservation::isActive() const {
  return active;
}

void Reservation::setActualSlot(int slot) {       //saves actual parked slot and checks violations

  actualSlot = slot;

if (actualSlot != reservedSlot)
  wrongSlot = true;

}

void Reservation::closeReservation() {           //marks reservation as closed 
  active = false;
}



