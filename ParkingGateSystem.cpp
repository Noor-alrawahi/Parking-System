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
    ParkingGateSystem() {

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
