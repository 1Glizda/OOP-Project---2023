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

    friend ostream& operator<<(ostream& os, const EventLocation& eventLocation);
    friend istream& operator>>(istream& is, EventLocation& eventLocation);
    friend ifstream& operator>>(ifstream& ifs, EventLocation& eventLocation);

public:
    EventLocation() {
        this->maxSeatsNr = 1;
        this->noRows = 1;
        this->zones = ZoneTypes(Nord);
        this->seatsPerRow = 1;
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

    void writeTextFile() {
        ofstream txt_f("EventLocation.txt", ios::app);

        txt_f << this->maxSeatsNr << "\n";
        txt_f << this->noRows << "\n";
        txt_f << this->zones << "\n";
        txt_f << this->seatsPerRow << "\n\n";

        txt_f.close();
        cout << "Text file written successfully.\n";
    }

    void readTextFile(vector<EventLocation>& locations) {
        ifstream txt_f("EventLocation.txt");

        while (!txt_f.eof()) {
            EventLocation l;
            
            txt_f >> l.maxSeatsNr;
            txt_f >> l.noRows;
            int tempZone;
            txt_f >> tempZone;
            l.zones = static_cast<ZoneTypes>(tempZone);

            txt_f >> l.seatsPerRow;
            cout << l;

            locations.push_back(l);
        }

        txt_f.close();
        cout << "Text file read successfully.\n";
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

    EventLocation operator++() {
        // Pre-increment operator
        maxSeatsNr++;
        return *this;
    }

    EventLocation operator++(int) {
        // Post-increment operator
        EventLocation temp = *this;
        maxSeatsNr++;
        return temp;
    }

    operator int() const {
        // Implicit conversion to int
        return maxSeatsNr;
    }

    explicit operator float() const {
        // Explicit conversion to float
        return static_cast<float>(maxSeatsNr) / noRows;
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
    cout << "Enter Even_Location details:\n\n";

    int maxSeatsNr, noRows, zoneInt;
    ZoneTypes zones;

    do {
    cout << "Max number of seats (integer): ";
    is >> maxSeatsNr;
    if(eventLocation.maxSeatsNr <= 0) {
        cerr << "Invalid input. Please try again.\n";
        is.clear();  
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (eventLocation.maxSeatsNr <= 0);
    eventLocation.setMaxSeatsNr(maxSeatsNr);

    do {
    cout << "Number of rows (integer): ";
    is >> noRows;
    if(eventLocation.noRows <= 0) {
        cerr << "Invalid input. Please try again.\n";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (eventLocation.noRows <= 0);
    eventLocation.setNoRows(noRows);

    do {
    cout << "Zone (0 for East, 1 for South, 2 for Nord, 3 for West): ";
    is >> zoneInt;
    if(zoneInt < 0 ||zoneInt > 3) {
        cerr << "Invalid input. Please try again.\n";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    zones = static_cast<ZoneTypes>(zoneInt);
    } while (zoneInt < 0 || zoneInt > 3);
    eventLocation.setZones(zones);

    return is;
}
