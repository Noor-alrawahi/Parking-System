// payment class
#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;
class Payment{
private:
  double amount;
public:
  Payment();

  void calculate( double rate, int duration, bool wrongSlot, bool disabledviolation, bool disabledPermit);
  void display() const;
};

#endif
