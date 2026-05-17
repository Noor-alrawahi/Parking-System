#include "Reservation.h"

Reservation::Reservation() {

reservationID = 0;
customerID = 0;
reservedSlot = 0;
actualSlot = 0;
wrongSlot = false;
active = false;
}

Reservation::Reservation(
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

bool Reservation::hasWrongSlot() const {
  return wrongSlot;
}

bool Reservation::isActive() const {
  return active;
}

void Reservation::setActualSlot(int slot) {

  actualSlot = slot;

if (actualSlot != reservedSlot)
  wrongSlot = true;

}

void Reservation::closeReservation() {
  active = false;
}



