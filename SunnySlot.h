#ifndef SUNNYSLOT_H
#define SUNNYSLOT_H
#include "parkingSlot.h"

class SunnySlot final : public ParkingSlot{
public:
SunnySlot(int num, bool disabled);

string getType() const override;
double getRate() const override;
};

#endif
