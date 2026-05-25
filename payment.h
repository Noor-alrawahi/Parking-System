// payment.h

#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;

// Payment class 
// Calculates and displays parking payment.

class Payment{
private:

// Final payment amount 
  double amount;

public:

// Constructor
  Payment();

// Calculates total payment
  void calculate( double rate, double duration, bool wrongSlot, bool disabledViolation, bool disabledPermit);

// Displays payment amount
  void display() const;
};

#endif
