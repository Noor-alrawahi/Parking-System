// Customer class 

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
//customer class to store customer information and validation 
class Customer {
private:

int customerID;
string name;
string phone;
string plateNumber;
//indicates if customer has disabled permit
bool disabledPermit;
static int totalCustomers;
static bool isDigitChar(char c);
static bool isLetterChar(char c);
static bool isDigitsOnly(string s);
static int stringToInt(string s);
static string toUpperText(string s);
static string getCurrentTimeString();


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
static double readTimeAsMinutes(string message);

void setData( int id, string n, string ph, string plate, bool permit);
int getID() const;
bool hasDisabledPermit() const;
static int getTotalCustomers();
bool operator==(const Customer & other);

friend void displayCustomer(const Customer & c);
};
void displayCustomer(const Customer & c);

#endif



