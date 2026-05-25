#include "ParkingGateSystem.h"
#include <iostraem>
#include <ctime>

using namespace std;
static double getOmanTimeMinutes(){                         //to get current oman time
    time_t now =time(0);
    now += 4 * 3600;
    tm* t = gmtime(&now);
    return t ->tm_hour * 60 + t->tm_min;
}

ParkingGateSystem::ParkingGateSystem() {                                                 //composition

        slots.push_back(new SunnySlot(1, false));                    // sunny slots
        slots.push_back(new SunnySlot(2, false));
    
        slots.push_back(new ShadedSlot(3, false));                   //shaded slots
        slots.push_back(new ShadedSlot(4, false));
    
        slots.push_back(new ShadedSlot(5, true));                    //shaded, diabled slots
        slots.push_back(new ShadedSlot(6, true));

        customerCount = 0;
        reservationCount = 0;
        sessionCount = 0;
    }

ParkingGateSystem::~ParkingGateSystem() {                           // destructor
        for (ParkingSlot* s : slots)
          delete s;
    }

Customer* ParkingGateSystem::findCustomer(int id) {                // to find customer
    for (int i = 0; i < customerCount; i++){
        if (customers[i].getID() == id)
            return &customers[i];
    }
    return NULL;                                                  // customer not found
}

Reservation* ParkingGateSystem::findReservation(int reservationID) {                                                // find reservation
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].isActive() && reservations[i].getReservationID() == reservationID)
            return &reservations[i];
    }
    return NULL;                                                                                                   // reservation not found
}

ParkingSession* ParkingGateSystem::findSession(int reservationID) {                                                // find session
    for (int i = 0; i < sessionCount; i++) {
        if (sessions[i].isOccupied() && sessions[i].getReservationID() == reservationID)
            return &sessions[i];                                                                                   // session not found
    }
    return NULL;
}


int ParkingGateSystem::getOccupiedCount() const {                                                                  // counts occupied slots
        int count = 0;
        for (ParkingSlot* s : slots){
            if (s->isOccupied())
                count++;
        }

        return count;
    }

int ParkingGateSystem::getAvailableCount() const {                            //counts avalibe slots
      return slots.size() - getOccupiedCount();
    }

void ParkingGateSystem::registerCustomer() {                                  // register costumer
        if (customerCount >= MAX_CUSTOMERS) {                                 // checks if customer array is full 
            cout << "ERROR: Customer list is full.\n";
            return;
        }

        int id = Customer::readExactDigitsInt("Enter customer ID: ", 8);           // reads customer id

        if (findCustomer(id) != NULL){
            cout << "ERROR: Customer ID already exists.\n";
            return;
      }

      string name = Customer::readName();                                          // reades customer information

      string phone = Customer::readPhone();

      string plate = Customer::readPlateNumber();

      bool permit = Customer::readDisabledPermit();

      customers[customerCount].setData(                                        // stores customer data
          id,
          name,
          phone,
          plate,
          permit
      );

      customerCount++;

      cout<<"Customer registered successfully.\n";
    }

void ParkingGateSystem::showSlots() {                                           // show parking slots
        cout << "\n==== PARKING SLOTS =====\n";
        for (ParkingSlot* s : slots)                                            // displays parking slots
            s->display();

        cout << "\nOccupied Slots: "<< getOccupiedCount()<< endl;

        cout << "Available Slots: "<< getAvailableCount()<< endl;
    }

void ParkingGateSystem::reserveSlot() {                                                      // reserve slot
        int customerID = Customer::readExactDigitsInt("Enter customer ID: ", 8 );

        Customer* customer = findCustomer(customerID);                                       // find customer
        if (customer == NULL) {
            cout<< "ERROR: Customer not found.\n";
            return;
        }
        int slotNum = Customer::readInt("Enter slot number: ", 1, 6);  
        ParkingSlot* slot = slots[slotNum - 1];                                             // gets slot object from vector

        if (slot->isReserved() || slot->isOccupied()){                                      // check if slot ia already reserved or occupied

            cout << "ERROR: Slot unavalible.\n";
            return;
        }

        if (slot->isDisabledOnly() && !customer->hasDisabledPermit()) {

            cout << "ERROR: Disabled customers only.\n";
            return;
        }

        reservations[reservationCount] =                                                    // creates reservation object
            Reservation(reservationCount + 1, customerID, slotNum );

        slot->reserve();                                                                    // marks slot as reserved
 
        cout << "Reservation successful.\n";
        cout << "Reservation ID: " << reservationCount + 1 <<endl;

        reservationCount++;
        }

void ParkingGateSystem::enterGate() {                                                        // enter gate

    int reservationID = Customer::readInt("Enter reservation ID: ", 1, 1000 );

    Reservation* res = findReservation(reservationID);
    if (res == NULL) {
        cout << "ERROR: Reservation not found.\n";
        return;
}

    int actualSlot = Customer::readInt("Enter actual parked slot: ", 1, 6 );
    ParkingSlot* slot = slots[actualSlot - 1];

    if (slot->isOccupied()) {
        cout << "ERROR: Slot already occupied.\n";
        return;
}
    double startMinutes = getOmanTimeMinutes();                                              // record entery time
    res->setActualSlot(actualSlot);
    slot->occupy();

    sessions[sessionCount].startSession(reservationID, startMinutes );                       // start parking session
    sessionCount++;

    cout << "Vehicle entered successfully.\n";
    cout << "Entry time recorded automatically (Oman time ). \n";
        
    if (res->hasWrongSlot())                                                                 // check wrong slots
    cout << "Wrong slot violation detected.\n";
}

void ParkingGateSystem::exitGate() {                                                         // exit gate
    int reservationID = Customer::readInt("Enter reservation ID: ", 1, 1000 );

    Reservation* res = findReservation(reservationID);                                       // find reservation 
    if (res == NULL) {  
        cout << "ERROR: Reservation not found.\n";
        return;
}

    ParkingSession* session = findSession(reservationID);
    if (session == NULL) {
        cout << "ERROR: No active session found.\n";
        return;
}

    double endMinutes = getOmanTimeMinutes();                                                // record exit time

    session->endSession(endMinutes);

    double duration = session->getDuration();                                               // calculate parking duration 

    int actualSlotNumber = res->getActualSlot();                                            // get actual parking slot

    ParkingSlot* actualSlot = slots[actualSlotNumber - 1];

    Customer* customer = findCustomer( res->getCustomerID() );                              // finds customer
 
    bool disabledPermit = customer->hasDisabledPermit();                                    // checks disabled permit

    bool disabledViolation = actualSlot->isDisabledOnly() && !disabledPermit;               //check disabled parking violation


    Payment payment;                                                                        // calculate payment amount
    payment.calculate(
        actualSlot->getRate(),
        duration,
        res->hasWrongSlot(),
        disabledViolation,
        disabledPermit
    );

    cout << "\n===== PAYMENT SUMMARY =====\n";                                              // display payment details
    cout << "Duration: " << duration <<" minutes(s)\n";

    if (res->hasWrongSlot())                                                                // wrong slot fine
        cout << "Wrong slot penalty: 5 OMR\n";

    if (disabledViolation)                                                                  // disabled parking fine
        cout << "Disabled parking violation: 50 OMR\n";

    if (disabledPermit)                                                                     // free parking for disabled customers
        cout << "Disabled customer: FREE parking\n";

    
    payment.display();                                                                      // display final payment
    
    actualSlot->freeSlot();                                                                 // free parking slot
    res->closeReservation();                                                                // close reservation

    cout << "Exit gate opened.\n";
}
