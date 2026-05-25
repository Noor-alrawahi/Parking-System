#include "parkingSlot.h"

//constructor
ParkingSlot::ParkingSlot(int num, bool disabled){
slotNumber=num;
occupied=false;
reserved=false;
disabledOnly=disabled;
}

ParkingSlot::~ParkingSlot() {}


int ParkingSlot::getSlotNumber() const{
  return slotNumber;  }

bool ParkingSlot::isOccupied() const{
  return occupied;  }

bool ParkingSlot::isReserved() const{
  return reserved;  }

bool ParkingSlot::isDisabledOnly() const{
  return disabledOnly;  }

void ParkingSlot::reserve(){
  reserved=true;  }

void ParkingSlot::occupy(){
  occupied=true;  }

//available, not occupied and not reserved
void ParkingSlot::freeSlot(){
  occupied=false;
  reserved=false;  }

void ParkingSlot::display() const{
  cout<<"Slot "<<slotNumber<<" | "<<getType();
if (disabledOnly)
  cout<<" | Disabled Only";
cout<<" | ";
if (occupied)
  cout<<"Occupied";
else if (reserved)
  cout<<"Reserved";
else
  cout<<"Available";

cout<<endl;
}

bool ParkingSlot::operator==(const ParkingSlot& other){
  return slotNumber==other.slotNumber;
}
