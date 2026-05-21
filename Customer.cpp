// Customer class

#include "Customer.h"

int Customer::totalCustomers = 0;

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
string Customer::getCurrentTimeString(){
  time_t now = time(0);
now+=4*3600;
tm*t = gmtime(&now);
int hour24 = t->tm_hour;
int mins = t->tm_min;

string ampm = "AM";
int hour12 = hour24;
if(hour24==0)
  hour12=12;
else if (hour24==12)
  ampm = "PM";
else if (hour24>12){
hour12=hour24-12;
ampm="PM";
}
string result="";
if (hour12>=10){
result+=(char)(hour12/10+'0');
result+=(char)(hour12%10+'0');
}
else {
result+=(char)(hour12+'0');
}
result+=':';
result+=(char)(mins/10+'0');
result+=(char)(mins%10+'0');
result+='';
result+=ampm;

return result;
}

Customer::Customer(){
customerID = 0;
name="";
phone="";
plateNumber="";
disabledPermit=false;
}
int Customer::readInt(string message, int minValue, int maxValue){
string input;
int value;

while(true){
cout<<message;
getline(cin, input);

if(!isDigitsOnly(input)){
cout<<"ERROR: Please enter number only.\n";
continue;
}
value = stringToInt(input);
if(value<minValue||value>maxValue){
cout<<"ERROR : Number must be between "<<minValue<<"and"<<maxValue<<".\n";
continue;
}
return value;
}
}
int Customer::readExactDigitsInt(string message, int digits){
  string input;
while(true){
cout<<message;
getline(cin,input);

if(!isDigitsOnly(input)){
cout<<"ERROR: Please enter numbers only.\n";
continue;
}
if(input.length()!=digits){
cout<<"ERROR:ID must be exactly"<<digits<<"digits.\n";
continue;
}
return stringToInt(input);
}
}
string Customer::readName(){
  string name;
while(true){
cout<<"Enter name:";
getline(cin, name);

if(name==""){
cout<<"ERROR: Name cannot be empty.\n";
continue;
}
string clean = "";
for(charc:input){
  if(c!=''){
  if(c>='a'&& c<='Z')
  clean+=(char)(c-32);
  else
  clean+=c;
  }
}
int colonPos=-1;
for(int i=0;i<(int)clean.length();i++){
if(clean[i]==':'){
colonPos=i;
break;
}
}
if(colonPos ==-1){
cout<<'Error:Missing colon.Use H:MM format (e.g. 4:30 PM).\n";
continue;
}
string hourStr=clean.substr(0,colonPos);
string rest = clean.substr(colonPos +1);
string minStr = "";
string ampm = "";
for(int i =0; i<(int)rest.length(); i++) {
if(isDigitChar(rest[i]))
  minStr+= rest[i];
else{
ampm = rest.substr(i);
break;
}
}



    

