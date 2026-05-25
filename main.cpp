#include "ParkingGateSystem.h"
#include "Customer.h"
#include<iostream>
using namespace std;

int main() {

  ParkingGateSystem system;

 int choice;
 do {

   cout<< "\n====== SMART PARKING GATE SYSTEM ======\n";

   cout<<"1. Register Customer\n";
   cout<<"2. Show Parking Slots\n";
   cout<<"3. Reserve Slot\n";
   cout<<"4. Enter Gate and Park\n";
   cout<<"5. Exit Gate and Pay\n";
   cout<<"0. Exit Program\n";

   choice=
     Customer::readInt( "Enter choice: ", 0,5 );

   if ( choice == 1)
        system.registerCustomer();
   else if ( choice == 2)
       system.showSlots();
   else if ( choice== 3)
       system.reserveSlot();
   else if ( choice==4 )
      system.enterGate();
   else if (choice==5 )
     system.exitGate();
   else if ( choice ==0)
     cout<<"Program ended.\n";
 } while (choice!=0);

return 0;
}


     
      
