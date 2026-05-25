#ifndef SHADEDSLOT_H
#define SHADEDSLOT_H
#include "ParkingSlot.h"

class ShadedSlot final : public ParkingSlot{
public:
ShadedSlot(int num,bool disabled);

string getType() const override;
double getRate() const override;
};

#endif
