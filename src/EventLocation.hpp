#include <string>
#include <iostream>

using namespace std;

enum ZoneTypes {
    East, South, Nord, West
};

class EventLocation{ 
    int maxSeatsNr;
    int noRows;
    ZoneTypes zones;
    const int seatsPerRow;

public:
    EventLocation() : seatsPerRow(1) { 
        this-> maxSeatsNr = 1;
        this-> noRows = 1;
        this-> zones = ZoneTypes(Nord);
    }

    EventLocation(int MaxSeatsNr, int NoRows, ZoneTypes Zones, int SeatsPerRow) : seatsPerRow(SeatsPerRow) {
        this-> maxSeatsNr = MaxSeatsNr;
        this-> noRows = NoRows;
        this-> zones = Zones;
    }

    void showObject() {
        cout << "This is the max nr of seats: " << maxSeatsNr << "\nThis is the no. of rows: " << noRows << "\nThis is the zone: " << zones
        << "\nThis is the nr of seats per row: " << seatsPerRow << endl << endl;    }
};