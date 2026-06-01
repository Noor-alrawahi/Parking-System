#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
private:
int reservationID;   //unique reservation ID
int customerID;      //stores customer ID linked to reservation 
int reservedSlot;    //slot selected during reservation 
int actualSlot;      //actual slot used by the customer 
bool wrongSlot;      //true if customer parked in the wrong slot
bool active;         //indicates wheather the reservation is active 

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


