#include "ParkingSlot.h"

//constructor
ParkingSlot::ParkingSlot(int num, bool disabled){
slotNumber=num;
occupied=false;
reserved=false;
disabledOnly=disabled;
}

//destructor
ParkingSlot::~ParkingSlot() {}


int ParkingSlot::getSlotNumber() const{
  return slotNumber;  }

bool ParkingSlot::isOccupied() const{
  return occupied;  }

bool ParkingSlot::isReserved() const{
  return reserved;  }

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

//sunny class
SunnySlot::SunnySlot(int num, bool disabled): ParkingSlot(num, disabled) {}

string SunnySlot::getType() const{
  return "Sunny Slot";  }

double SunnySlot::getRate() const{
  return 1;  }

//shadded class
ShaddedSlot::ShaddedSlot(int num, bool disabled): ParkingSlot(num, disabled) {}

string ShaddedSlot::getType() const{
  return "Shadded Slot";  }

double ShaddedSlot::getRate() const{
  return 2;  }
