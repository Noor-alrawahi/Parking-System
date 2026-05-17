#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
private:
int reservationID;
int customerID;
int reservedSlot;
int actualSlot;
bool wrongSlot;
bool active;

public:
Reservation();

Reservation(
int resID,
int custID,
int slot
);

int getReservationID() const;
int getCustomerID() const;
int getReservedSlot() const;
int getActualSlot() const;

bool hasWrongSlot() const;
bool isActive() const;

void setActualSlot(int slot);

void closeReservation();
};

#endif


