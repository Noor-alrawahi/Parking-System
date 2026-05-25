// Customer class

#include "Customer.h"

int Customer::totalCustomers = 0;

// checks if the character is a digit from 0-9
bool Customer::isDigitChar(char c) {
return c >='0' && c<='9';
}
//checks if character is an English capital or small letter
bool Customer::isLetterChar(char c) {
return (c >= 'A' && c <= 'Z') ||
  (c >= 'a' && c <= 'z');
}

//checks if string contains digits only
bool Customer::isDigitsOnly(string s){
  if(s=="")
    return false;
for(char c : s){
if(!isDigitChar(c))
  return false;
}
return true;
}

//convert string to integer
int Customer::stringToInt(string s){
  int number =0;
for(char c : s )
  number=number*10+(c-'0');
return number;
}

//convert lowercase letters to uppercase
string Customer::toUpperText(string s){
  for(int i=0; i<(int)s.length(); i++){
if ( s[i]>='a'&& s[i]<='z')
  s[i] = s[i]-32;
  }
return s;
}

//get cuurent oman time as formatted string 
string Customer::getCurrentTimeString(){
  time_t now = time(0);
  //add 4 hours for oman timezone 
now+=4*3600;
tm*t = gmtime(&now);
int hour24 = t->tm_hour;
int mins = t->tm_min;

string ampm = "AM";
int hour12 = hour24;
  // convert from 24 hour to 12 hour format
if(hour24==0)
  hour12=12;
else if (hour24==12)
  ampm = "PM";
else if (hour24>12){
hour12=hour24-12;
ampm="PM";
}
string result="";
  // add hour digits
if (hour12>=10){
result+=(char)(hour12/10+'0');
result+=(char)(hour12%10+'0');
}
else {
result+=(char)(hour12+'0');
}
  //add colon and minutes
result+=':';
result+=(char)(mins/10+'0');
result+=(char)(mins%10+'0');
result+=' ';
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
//read integer with validation and range checking
int Customer::readInt(string message, int minValue, int maxValue){
string input;
int value;

while(true){
cout<<message;
getline(cin, input);
//validate numeric input
if(!isDigitsOnly(input)){
cout<<"ERROR: Please enter numbers only.\n";
continue;
}
  //converts string to integer
value = stringToInt(input);
  //validate range
if(value<minValue||value>maxValue){
cout<<"ERROR: Number must be between "
  <<minValue<<" and "
  <<maxValue<<".\n";
continue;
}
return value;
}
}
//read integer with exact digit count
int Customer::readExactDigitsInt(string message, int digits){
  string input;
while(true){
cout<<message;
getline(cin,input);
//ensures input contains digits only 
if(!isDigitsOnly(input)){
cout<<"ERROR: Please enter numbers only.\n";
continue;
}
  //ensure exact length
if((int)input.length()!=digits){
cout<<"ERROR: ID must be exactly "
  <<digits<<" digits.\n";
continue;
}
return stringToInt(input);
}
}
//read and validate customer name
string Customer::readName(){
  string name;
while(true){
cout<<"Enter name: ";
getline(cin, name);

//prevent empty names
if(name==""){
cout<<"ERROR: Name cannot be empty.\n";
continue;
}
  bool valid = true;
  //ensure name contains letter and spaces only 
  for(char c: name){
    if(!isLetterChar(c) && c!=' '){
      valid=false;
      break;
    }
  }
  if (!valid){
    cout<<"ERROR: Name must contain letters only.\n";
    continue;
  }
  return name;
}
}
//read and validate oman phone number
string Customer::readPhone(){
  string phone;
  while(true){
    cout<<"Enter phone number: ";
    getline(cin, phone);
    //digits only
    if(!isDigitsOnly(phone)){
      cout<<"ERROR: Phone must contain numbers only.\n";
      continue;
    }
    //Must be exactly 8 digits 
    if(phone.length() !=8){
      cout<<"ERROR: Phone must be exactly 8 digits.\n";
      continue;
    }
    //oman mobile number starts with 9 or 7
    if(phone[0] !='9' && phone[0] !='7'){
      cout<<"ERROR: Oman numbers start with 9 or 7.\n";
      continue;
    }
    return phone;
  }
}
//read and validate plate number
string Customer::readPlateNumber(){
  string plate;
  while(true){
    cout<<"Enter vehicle plate number: ";
    getline(cin, plate);
    //prevent empty plate number
    if(plate==""){
      cout<<"ERROR: Plate number cannot be empty.\n";
      continue;
    }

    int letters=0, digits=0;
    bool invalid = false;
    //count letters and digits
    for(char c : plate){
      if(isLetterChar(c))  letters++;
      else if(isDigitChar(c)) digits++;
      else{ invalid=true; break;}
    }
    if(invalid){
      cout<<"ERROR: Plate must contain letters and numbers only.\n";
      continue;
    }
    if(letters<1 || letters >2 ){
      cout<<"ERROR: Plate must contain 1 or 2 letters.\n";
      continue;
    }

    if ( digits <1 || digits>5){

      cout<<"ERROR: Plate must contain maximum 5 digits.\n";
      continue;
    }
    return plate;

  }
}

bool Customer::readYesNo( string message) { 
  string input;
  while (true){
    cout<<message;
    getline(cin, input);
    if(input=="y" || input=="Y") return true;
    if(input=="n" || input=="N") return false;
    cout<<"ERROR: Please enter y or n only.\n";
  }
}

bool Customer::isValidPermit(string permit){
  permit = toUpperText(permit);
  string validPermits[4] = {
  "DP1001","DP1002","DP1003","DP2026" 
};

  //compare entered permit with valid permits
  for(int i=0; i< 4; i++){
    if(permit == validPermits[i])
      return true;
  }
  return false;
}
bool Customer::readDisabledPermit(){
  bool hasPermit = readYesNo("Does customer have disabled permit? (y/n): ");
  if(!hasPermit)
    return false;
  string permit;

  while(true){
    cout<<"Enter disabled permit number: ";
    getline(cin, permit);

    if(permit==""){
      cout<<"ERROR: Permit number cannot be empty.\n";
      continue;
    }
    if(isValidPermit(permit)){
      cout<<"Permit verified successfully.\n";
      return true;
    }
    cout<<"ERROR: Invalid permit number.\n";
  }
}

int Customer::convertTo24Hour(int hour, string ampm){
  if(ampm=="AM"){
    if(hour==12) return 0;
    return hour;
  }
  if (hour==12) return 12; 
  return hour +12;
}

double Customer::readTimeAsMinutes(string message){
string input;

while(true){
  cout<<message
    <<" (current Oman time is "
    <<getCurrentTimeString()
    <<") "
    <<"(e.g. 4:30PM or 4:30 PM): ";
    getline(cin, input);

  if(input==""){
    cout<<"ERROR: Time cannot be empty.\n";
    continue;
  }
  


        

    
    
string clean = "";
for(char c:input){
  if(c!=' '){
  if(c>='a'&& c<='z')
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
cout<<"ERROR: Missing colon. Use H:MM format (e.g. 4:30PM).\n";
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
ampm =rest.substr(i);
break;
}
}
if (hourStr == ""){
cout<<"ERROR: Hour cannot be empty.\n";
continue;
}
bool hourValid=true;
for(char c : hourStr){
if(!isDigitChar(c)){
hourValid = false;
break;
}
}
if(!hourValid){
cout<<"ERROR: Hour must be a number.\n";
continue;
}
if(minStr == ""){
cout<<"ERROR: Minutes cannot be empty.\n";
continue;
}
if(minStr.length() !=2){
cout<<"ERROR: Minutes must be exactly 2 digits (e.g. 4:05 not 4:5).\n";
  continue;
}
if (ampm!= "AM" && ampm != "PM") {
cout<<"ERROR: Time must end with AM or PM.\n";
continue;
}
  
int hour =0;
for(char c : hourStr)
  hour=hour*10+(c-'0');
  
int minutes = 0;
  for(char c : minStr)
    minutes = minutes*10 +(c-'0');
  
if(hour < 1 || hour > 12) {
cout <<"ERROR: Hour must be between 1 and 12.\n";
continue;
}
  
if (minutes>59){
  cout<<"ERROR: Minutes must be between 00 and 59.\n";
continue;
}
  
int hour24= convertTo24Hour(hour, ampm);
    return(double)(hour24*60+minutes);
}
}

void Customer::setData(int id, string n, string ph, string plate, bool permit){
customerID = id;
name = n;
phone = ph;
plateNumber = plate;
disabledPermit = permit;
totalCustomers++;
}

int Customer::getID() const
{return customerID;}
bool Customer::hasDisabledPermit()
const{ return disabledPermit;}
int Customer::getTotalCustomers()
{ return totalCustomers;}

bool Customer::operator==(const Customer & other){
return customerID==other.customerID;
}
//display customer information
void displayCustomer(const Customer & c){
  cout<<"\nCustomer Information\n";
cout<<"ID: "<<c.customerID<<endl;
cout<<"Name: "<<c.name<<endl;
cout<<"Phone: "<<c.phone<<endl;
}




    

