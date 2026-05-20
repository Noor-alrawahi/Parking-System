#include "SunnySlot.h"

SunnySlot::SunnySlot(int num, bool disabled): ParkingSlot(num, disabled) {}

string SunnySlot::getType() const{
  return "Sunny Slot";
}

double SunnySlot::getRate() const {
  return 1;
}

