#include <iostream>
#include <string>

using namespace std;

enum ZoneTypes {
    East, South, Nord, West
};

class EventLocation {
protected:
    int maxSeatsNr;
    int noRows;
    ZoneTypes zones;
    static float seatsPerRow;

public:
    EventLocation() {
        this->maxSeatsNr = 1;
        this->noRows = 1;
        this->zones = ZoneTypes(Nord);
    }

    EventLocation(int MaxSeatsNr, int NoRows, ZoneTypes Zones) {
        if (MaxSeatsNr > 0) {
            this->maxSeatsNr = MaxSeatsNr;
            this->noRows = NoRows;
        } else {
            this->maxSeatsNr = 0;
            this->noRows = 0;
        };
        this->zones = Zones;
    }

    static float getSeatsPerRow()  {
        return seatsPerRow;
    }

    int getMaxSeatsNr() const {
        return maxSeatsNr;
    }

    void setMaxSeatsNr(int MaxSeatsNr) {
        if (MaxSeatsNr > 0) {
            maxSeatsNr = MaxSeatsNr;
        } else {
            maxSeatsNr = 0;
        }
        seatsPerRow = maxSeatsNr / noRows;
    }

    int getNoRows() const {
        return noRows;
    }

    void setNoRows(int NoRows) {
        if (NoRows > 0) {
            noRows = NoRows;
        } else {
            noRows = 0;
        }
        seatsPerRow = maxSeatsNr / noRows;
    }

    string getZones() const {
        string zoneString;

        switch (zones) {
        case East:
            zoneString = "East";
            break;
        case South:
            zoneString = "South";
            break;
        case Nord:
            zoneString = "Nord";
            break;
        case West:
            zoneString = "West";
            break;
        default:
            zoneString = "Unknown Zone";
        }

        return zoneString;
    }


    void setZones(ZoneTypes Zones) {
        zones = Zones;
    }

     void showObject() {
        cout << "This is the max nr of seats: " << maxSeatsNr << "\nThis is the no. of rows: " << noRows
             << "\nThis is the zone: " << zones << "\nThis is the nr of seats per row: " << seatsPerRow << endl
             << endl;
    }

    void deleteEventLocation() {
        maxSeatsNr = 0;
        noRows = 0;
        zones = ZoneTypes(Nord);
        seatsPerRow = 0;
    }

};

float EventLocation::seatsPerRow = 0;

ostream& operator<<(ostream& os, const EventLocation& eventLocation) {
    os << "Max number of seats: " << eventLocation.getMaxSeatsNr()
       << "\nNumber of rows: " << eventLocation.getNoRows()
       << "\nZone: " << eventLocation.getZones()
       << "\nNumber of seats per row: " << EventLocation::getSeatsPerRow() << endl << endl;
    return os;
}

istream& operator>>(istream& is, EventLocation& eventLocation) {
    cout << "Enter Event Location details:\n";

    // Accessing the public setter methods instead of protected members directly
    int maxSeatsNr, noRows;
    ZoneTypes zones;

    cout << "Max number of seats: ";
    is >> maxSeatsNr;
    eventLocation.setMaxSeatsNr(maxSeatsNr);

    cout << "Number of rows: ";
    is >> noRows;
    eventLocation.setNoRows(noRows);

    cout << "Zone (0 for East, 1 for South, 2 for Nord, 3 for West): ";
    int zoneInt;
    is >> zoneInt;
    zones = static_cast<ZoneTypes>(zoneInt);
    eventLocation.setZones(zones);

    return is;
}
