#include "ShadedSlot.h"

ShadedSlot::ShadedSlot(int num, bool disabled):ParkingSlot(num, disabled) {}

string ShadedSlot::getType() const{
  return "Shaded Slot";
}

double ShadedSlot::getRate() const{
  return 2;
}
