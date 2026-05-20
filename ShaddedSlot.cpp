#include "ShaddedSlot.h"

ShaddedSlot::ShaddedSlot(int num, bool disabled):ParkingSlot(num, disabled) {}

string ShaddedSlot::getType() const{
  return "Shadded Slot";
}

double ShaddedSlot::getRate() const{
  return 2;
}
