// Customwe class

#include"Customer.h"

int Customer :: totalCustomers = 0;
Customer:: () {
customerID = 0;
name="";
phone="";
plateNumber="";
disabledPermit= false;
}
bool Customer :: isDigitsOnly(string s){
  if(s=="")
    return false;
for(char c : s){
if(!isDigitChar(c))
  return false;
}
return true;
}
int Customer :: stringToInt(string s){
  int number =0;
for(char c : s )
  number=number*10+(c-'0');
return number;
}
    

