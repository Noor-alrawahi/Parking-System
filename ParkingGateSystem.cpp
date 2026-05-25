#include "ParkingGateSystem.h:
#include <iostrem>
#include <ctime>

using namespace std;
static double getOmanTimeMinutes(){
    time_t now =time(0);
    now += 4 * 3600;
    tm* t = gmtime(&now);
    return t ->tm_hour * 60 + t->tm_min;
}

ParkingGateSystem::ParkingGateSystem() {                                                 //constructor

        slots.push_back(new SunnySlot(1, false));
        slots.push_back(new SunnySlot(2, false));
        slots.push_back(new ShadedSlot(3, false));
        slots.push_back(new ShadedSlot(4, false));
        slots.push_back(new ShadedSlot(5, true));
        slots.push_back(new ShadedSlot(6, true));

        customerCount = 0;
        reservationCount = 0;
        sessionCount = 0;
    }

ParkingGateSystem::~ParkingGateSystem() {
        for (ParkingSlot* s : slots)
          delete s;
    }

Customer* ParkingGateSystem::findCustomer(int id) {
    for (int i = 0; i < customerCount; i++){
        if (customers[i].getID() == id)
            return &customers[i];
    }
    return NULL;
}

Reservation* ParkingGateSystem::findReservation(int reservationID) {
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].isActive() && reservations[i].getReservationID() == reservationID)
            return &reservations[i];
    }
    return NULL;
}

ParkingSession* ParkingGateSystem::findSession(int reservationID) {
    for (int i = 0; i < sessionCount; i++) {
        if (sessions[i].isOccupied() && sessions[i].getReservationID() == reservationID)
            return &sessions[i];
    }
    return NULL;
}


int ParkingGateSystem::getOccupiedCount() const {
        int count = 0;
        for (ParkingSlot* s : slots){
            if (s->isOccupied())
                count++;
        }

        return count;
    }

int ParkingGateSystem::getAvailableCount() const {
      return slots.size() - getOccupiedCount();
    }

void ParkingGateSystem::registerCustomer() {
        if (customerCount >= MAX_CUSTOMERS) {
            cout << "ERROR: Customer list is full.\n";
            return;
        }

        int id = Customer::readExactDigitsInt("Enter customer ID: ", 8);

        if (findCustomer(id) != NULL){
            cout << "ERROR: Customer ID already exists.\n";
            return;
      }

      string name = Customer::readName();

      string phone = Customer::readPhone();

      string plate = Customer::readPlateNumber();

      bool permit = Customer::readDisabledPermit();

      customers[customerCount].setData(
          id,
          name,
          phone,
          plate,
          permit
      );

      customerCount++;

      cout<<"Customer registered successfully.\n";
    }

void ParkingGateSystem::showSlots() {
        cout << "\n==== PARKING SLOTS =====\n";
        for (ParkingSlot* s : slots)
            s->display();

        cout << "\nOccupied Slots: "<< getOccupiedCount()<< endl;

        cout << "Available Slots: "<< getAvailableCount()<< endl;
    }

void ParkingGateSystem::reserveSlot() {
        int customerID = Customer::readExactDigitsInt("Enter customer ID: ", 8 );

        Customer* customer = findCustomer(customerID);
        if (customer == NULL) {
            cout<< "ERROR: Customer not found.\n";
            return;
        }
        int slotNum = Customer::readInt("Enter slot number: ", 1, 6);
        ParkingSlot* slot = slots[slotNum - 1];

        if (slot->isReserved() || slot->isOccupied()){

            cout << "ERROR: Slot unavalible.\n";
            return;
        }

        if (slot->isDisabledOnly() && !customer->hasDisabledPermit()) {

            cout << "ERROR: Disabled customers only.\n";
            return;
        }

        reservations[reservationCount] =
            Reservation(reservationCount + 1, customerID, slotNum );

        slot->reserve(); 

        cout << "Reservation successful.\n";
        cout << "Reservation ID: " << reservationCount + 1 <<endl;

        reservationCount++;
        }

void ParkingGateSystem::enterGate() {

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
    double startMinutes = getOmanTimeMinutes();
    res->setActualSlot(actualSlot);
    slot->occupy();

    sessions[sessionCount].startSession(reservationID, startMinutes );
    sessionCount++;

    cout << "Vehicle entered successfully.\n";
    cout << "Entry time recorded automatically (Oman time ). \n";
        
    if (res->hasWrongSlot())
    cout << "Wrong slot violation detected.\n";
}

void ParkingGateSystem::exitGate() {
    int reservationID = Customer::readInt("Enter reservation ID: ", 1, 1000 );

    Reservation* res = findReservation(reservationID);
    if (res == NULL) {
        cout << "ERROR: Reservation not found.\n";
        return;
}

    ParkingSession* session = findSession(reservationID);
    if (session == NULL) {
        cout << "ERROR: No active session found.\n";
        return;
}

    double endMinutes = getOmanTimeMinutes();

    session->endSession(endMinutes);

    double duration = session->getDuration();

    int actualSlotNumber = res->getActualSlot();

    ParkingSlot* actualSlot = slots[actualSlotNumber - 1];

    Customer* customer = findCustomer( res->getCustomerID() );
 
    bool disabledPermit = customer->hasDisabledPermit();

    bool disabledViolation = actualSlot->isDisabledOnly() && !disabledPermit;


    Payment payment;
    payment.calculate(
        actualSlot->getRate(),
        duration,
        res->hasWrongSlot(),
        disabledViolation,
        disabledPermit
    );

    cout << "\n===== PAYMENT SUMMARY =====\n";
    cout << "Duration: " << duration <<" minutes(s)\n";

    if (res->hasWrongSlot())
        cout << "Wrong slot penalty: 5 OMR\n";

    if (disabledViolation)
        cout << "Disabled parking violation: 50 OMR\n";

    if (disabledPermit)
        cout << "Disabled customer: FREE parking\n";

    
    payment.display();
    
    actualSlot->freeSlot();
    res->closeReservation();

    cout << "Exit gate opened.\n";
}
