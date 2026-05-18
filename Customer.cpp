// Customer class

#include "Customer.h"

int Customer::totalCustomers = 0;
Customer::Customer() {
customerID = 0;
name="";
phone="";
plateNumber="";
disabledPermit= false;
}
bool Customer::isDigitChar(char c) {
return c >='0' && c<='9';
}
bool Customer::isLetterChar(char c) {
return (c >= 'A' && c <= 'Z') ||
  (c >= 'a' && c <= 'z');
}
bool Customer::isDigitsOnly(string s){
  if(s=="")
    return false;
for(char c : s){
if(!isDigitChar(c))
  return false;
}
return true;
}
int Customer::stringToInt(string s){
  int number =0;
for(char c : s )
  number=number*10+(c-'0');
return number;
}
string Customer::toUpperText(string s){
  for(int i=0; i<s.length(); i++){
if ( s[i]>='a'&& s[i]<='z')
  s[i] = s[i]-32;
  }
return s;
}
bool Customer::operator==(const Customer & other)const {
  return customerID == other.customerID;
}

    

