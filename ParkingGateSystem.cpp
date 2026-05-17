class ParkingGateSystem{
private:
    vector<ParkingSlot*>slots;

    Customer customers[MAX_CUSTOMERS];
    Reservation resevations[MAX_RESERVATIONS];
    ParkingSession sessions[MAX_SESSIONS];

    int customerCount;
    int reservationCout;
    int sessionCount;


    Cusomer* findCustomer(int id){
        for (int i = 0; i < customerCount; i++){
          if (customers[i].getID() ==id)
            return &customers[i];
        }
      
        return NULL;
    }


    Reservation* findReservation(int reservationID){
        for (int i = 0; i < reservationCount; i++){
          if (reservation[i].isActive() &&
              reservation[i].getReservationID() == reservationID)
              return &reservation[i];
        }
      
        return NULL;
    }


    ParkingSession* findSession(int reservationID) {
        for (int i = 0; i < sessionCount; i++) {
          if (sessions[i].isOccupied() &&
              sessions[i].getReservationID() == reservationID)
              return &sessions[i];
        }

        return NULL;
    }
public:
    ParkingGateSystem() {                                                 #constructor

        slots.push_back(new SunnySlot(1, false));
        slots.push_back(new SunnySlot(2, false));
        slots.push_back(new ShadedSlot(3, false));
        slots.push_back(new ShadedSlot(4, false));
        slots.push_back(new ShadedSlot(5, true));
        slots.push_back(new ShadedSlot(6, true));

        customerCount = 0;
        reservationsCount = 0;
        sessionCount = 0;
    }

    ~ParkingGateSystem() {
        for (ParkingSlot* s : slots)
          delete s;
    }

    int getOccupiedCount() const {
        int count = 0;

        for (ParkingSlot* s : slots){
            if (s->isOccupied())
                count++;
        }

        return count;
    }

    int getAvailableCount() const {
      return slots.size() - getOccupiedCount();
    }

    void registerCustomer() {

        if (customerCount >= MAX_CUSTOMERS) {
            cout << "ERROR: Customer list is full.\n";
            return;
        }

        int id =
            customer::readExactDigitsInt(
                "Enter customer ID: ",
                8
            );

        if (findCustomer(id) != NULL){
            cout << "ERROR: Customer ID already exists.\n"
            return;
      }

      string name = Customer::readName();

      string phone = Customer::readPhone();

      string plate = customer::readPlateNumber();

      bool permit = Customer::readDisabledPermit();

      customers[customerCount].setData(
          id,
          name,
          phone,
          plate,
          permi,
      );

      customerCount++;

      cout<<"Customer registered successfully.\n";
    }

    void showSlots() {

        count << "\n==== PRKING SLOTS =====\n";

        for (ParkingSlot* s : slots)
            s->display();

        cout << "\nOccupied Slots: "
             << getOccupiedCount()
             << endl;

        cout << "Available Slots: "
             << getAvailableCount()
             << endl;
    }

    void reserveSlot() {
        int customerID = 
            Customer::readExaxtDigitsInt(
               "Enter customer ID: ",
        );

        Customer* customer =
            findCustomer(customerID);

        if (customer == NULL) {
            cout<< "ERROR: Customer not found.\n"
            return;

        int slotNum =
            Customer::readInt(
                "Enter slot number: ",
                1,
                6
        );

        ParkingSlot* slot = slots[slotNum - 1];

        if (slot->isReserved() || slot->isOccupied()){

            cout << "ERROR: Slot unavalible.\n";
            return;
        }

        if (slot->isDisabledOnly() && !customer->hasDisabledPermit()) {

            cout << "ERROR: Disabled customers only.\n
            return;
        }

        reservations[reservationCont] =
            Resercvation(
                reservationCount + 1,
                customerID,
                slotNum
            );

        slot->reserve(); 

        cout << "Reservation successful.\n;

        cout << "Reservation ID: "
             << reservationCount + 1
             <<endl;

        reservationCount++;
        }

void ParkingGateSystem::enterGate() {

    int reservationID =
customer::readInt(
"Enter reservation ID: ",
1,
1000
);

Reservation* res = 
findReservation(reservationID);

if (res == NULL) {

cout << "ERROR: Reservation not found.\n";
return;
}

int actualSlot =
Customer::readInt(
"Enter actual parked slot: ",
1,
6
);

ParkingSlot* slot =
slots[actualSlot - 1];

if (slot->isOccupied()) {

cout << "ERROR: Slot already occupied.\n";
return;
}

int startHour =
Customer::readHourWithAmPm(
"Enter start hour (example 2PM): "
);

res->setActualSlot(actualSlot);

slot->occupy();

sessions[sessionCount].startSession(
    resevationID,
    startHour
    );

sessionCount++;

cout << "Vehicle entered successfully.\n";

if (res->hasWrongSlot())
    cout << "Wrong slot violation detected.\n";
}

void ParkingGateSystem::exitGate() {

    int reservationID =
Customer::readInt(
"Enter reservation ID: ",
1,
1000
);

Reservation* res =
findReservation(reservationID);

if (res == NULL) {

cout << "ERROR: Reservation not found.\n";
return;
}

ParkingSession* session =
findSession(reservationID);

if (session == NULL) {

cout << "ERROR: No active session found.\n";
return;
}

int endHour = 
Customer::readHourWithAmPm(
"Enter exit hour (example 4PM): "
);

session->endSession(endHour);

int duration =
session->getDuration();

int actualSlotNumber = 
res->getActualSlot();

ParkingSlot* actualSlot =
slots[actualSlotNumber - 1];

Customer* customer =
findCustomer)
res->getCustomerID()
    );

bool disabledPermit =
customer->hasDisabledPermit();

bool disabledViolation =
actualSlot->isDisabledOnly()
&&
!disabledPermit;

Payment payment;

payment.calculate(
    actualSlot->getRate(),
    duration,
    res->hasWrongSlot(),
    disabledViolation,
    disabledPermit
    );

cout << "\n===== PAYMENT SUMMARY =====\n";

cout << "Duration: "
    << duration
    <<" hour(s)\n";

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



























