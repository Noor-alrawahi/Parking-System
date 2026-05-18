// Customer class 

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;
class Customer {

private:

int customerID;
string name;
string phone;
string plateNumber;
bool disabledPermit;
static int totalCustomers;
static bool isDigitChar(char c);
static bool isLetterChar(char c);
static bool isDigitsOnly(string s);
static int stringToInt(string s);
static string toUpperText(string s);

public:

Customer();
static int readInt(string message, int minValue, int maxValue);
static int readExactDigitsInt( string message, int digits);
static string readName();
static string readPhone();
static string readPlateNumber();
static bool readYesNo(string message);
static bool isValidPermit(string permit);
static bool readDisabledPermit();
static int convertTo24Hour( int hour, string ampm);
static int readHourWithAmPm(string message);

void setData( int d, string n, string ph, string plate, bool permit);
int getID() const;
bool hasDisabledPermit() const;
static int getTotalCustomers();
bool operator==(const Customer & other) const;

friend void displayCustomer(const Customer & c);
};

#endif



