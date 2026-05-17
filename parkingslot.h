#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H
#include <iostream>
#include <string>
using namespace std;

class ParkingSlot{

protected: //derived class can access this 
int slotNumber;
bool occupied;
bool reserved;
bool disabledOnly;

public:
ParkingSlot(int num, disabled); //constructor
virtual ~ParkingSlot(); //distructor

int getSlotNumber() const;
bool isOccupied() const;
bool isReserved() const;
bool isDisabledOnly() const;

void reserve();
void occupy();
void freeSlot();

virtual string getType() const = 0; //pure virtual
virtual double getRate() const = 0; //pure virtual
virtual void display() const;

bool operator==(const ParkingSlot& other);

}; //base class ends

class SunnySlot final : public ParkingSlot{ 

public:  
SunnySlot(int num, bool disabled);

string getType() const override;
double getRate() const override;

};

class ShaddedSlot final : public ParkingSlot{

public:
ShaddedSlot(int num, bool disabled);

string getType() const override;
double getRate() const override;

};

#endif


































