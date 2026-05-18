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
static bool is DigitChar(char c);
static bool is LetterChar(char c);
static bool is DigitsOnly(string s);
static int stringToInt(string s);
static string toUpperText(string s);

Public:

Customer();
static int readInt(string message, int minValue, int maxValue);
static int readExactDigitsInt( string message, int digits);
static string readName();
static striing readPhone();
static string readPlateNumber();
static bool readYesNo(string message);
static bool is ValidPermit(string permit);
static bool readDisabledPermit();
static int convertTo24Hour( int hour, string ampm);
static int readHourWithAmPm(string message);

void setData( int d, string n, string ph, string plate, bool permit);
int getID()const;
bool hasDisabledePermit()const;
static int getTotalCustomers();
bool operator==(const Customer & other)const;

friend void displayCustomer( const Customer & c);
};

#endif



