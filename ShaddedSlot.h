#ifndef SHADDEDSLOT_H
#define SHADDEDSLOT_H
#include "ParkingSlot.h"

class ShaddedSlot final : public ParkingSlot{
public:
ShaddedSlot(int num,bool disabled);

string getType() const override;
double getRate() const override;
};

#endif
