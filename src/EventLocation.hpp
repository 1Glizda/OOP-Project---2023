#include <string>
#include <iostream>

using namespace std;

enum ZoneTypes {
    East, South, Nord, West
};

ostream& operator<<(ostream& os, const ZoneTypes& zone) {
    switch (zone) {
        case East:
            os << "East";
            break;
        case South:
            os << "South";
            break;
        case Nord:
            os << "Nord";
            break;
        case West:
            os << "West";
            break;
        default:
            os << "Unknown Zone";
    }
    return os;
}

class EventLocation {
    int maxSeatsNr;
    int noRows;
    ZoneTypes zones;
    static float seatsPerRow;

public:
    EventLocation() {
        this->maxSeatsNr = 1;
        this->noRows = 1;
        this->zones = ZoneTypes(Nord);
        this->seatsPerRow = maxSeatsNr / noRows;
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
        this->seatsPerRow = maxSeatsNr / noRows;
    }

    static float getSeatsPerRow()  {
        return seatsPerRow;
    }

    void showObject() {
        cout << "This is the max nr of seats: " << maxSeatsNr << "\nThis is the no. of rows: " << noRows
             << "\nThis is the zone: " << zones << "\nThis is the nr of seats per row: " << seatsPerRow << endl
             << endl;
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

    ZoneTypes getZones() const {
        return zones;
    }

    void setZones(ZoneTypes Zones) {
        zones = Zones;
    }

};

float EventLocation::seatsPerRow = 0;

