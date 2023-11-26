#include <string>
#include <iostream>

using namespace std;

class Event {
    string date;
    string time;
    char* name;

    friend ostream& operator<<(ostream& os, const Event& event);
    friend istream& operator>>(istream& is, Event& event);

    bool isValidDate(const string& date) const {
        if (date.size() != 10 || date[2] != '-' || date[5] != '-') {
            return false; // Invalid format
        }

        for (int i = 0; i < 10; ++i) {
            if (i == 2 || i == 5) {
                continue; // Skip hyphens
            }

            if (!isdigit(date[i])) {
                return false; // Non-digit character found
            }
        }

        // Attempt to parse day, month, and year
        int day = stoi(date.substr(0, 2));
        int month = stoi(date.substr(3, 2));
        int year = stoi(date.substr(6, 4));

        // Check ranges
        return (day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 0);
    }

    bool isValidTime(const string& time) const {
        if (time.size() != 5 || time[2] != ':') {
            return false; // Invalid format
        }

        for (int i = 0; i < 5; ++i) {
            if (i == 2) {
                continue; // Skip colon
            }

            if (!isdigit(time[i])) {
                return false; // Non-digit character found
            }
        }

        // Attempt to parse hours and minutes
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));

        // Check ranges
        return (hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59);
    }

public:
    Event() {
        this->date = "12-12-2012";
        this->time = "00:00";
        this->name = new char[strlen("no name") + 1];
        strcpy(name, "no name");
    };

    Event(string Date, string Time, char* Name) {
        if (!isValidDate(Date) || !isValidTime(Time)) {
            throw invalid_argument("Invalid date or time");
        }
        this->date = Date;
        this->time = Time;
        this->name = new char(strlen(Name) + 1);
        strcpy(name, Name);
    }

    ~Event() {
        delete[] name;
    }

    string getDate() const {
        return date;
    }

     void setDate(const string& Date) {
        if (isValidDate(Date)) {
            date = Date;
        } else {
            cerr << "Invalid date format. Date not set." << endl;
        }
    }

    string getTime() const {
        return time;
    }

    void setTime(const string& Time) {
        if (isValidTime(Time)) {
            time = Time;
        } else {
            cerr << "Invalid time format. Time not set." << endl;
        }
    }

    char* getName() const {
        return name;
    }

    void setName(const char* Name) {
        delete[] name;
        name = new char[strlen(Name) + 1];
        strcpy(name, Name);
    }

    void showObject() {
    cout << "This is the date: " << date << "\nThis is the time: " << time << "\nThis is the name: " << name << endl << endl;
    }

    void deleteEvent() {
        date = "00-00-0000";
        time = "00:00";
        delete[] name;
        name = new char[strlen("no name") + 1];
        strcpy(name, "no name");
    }
};

ostream& operator<<(ostream& os, const Event& event) {
    os << "Date: " << event.getDate()
       << "\nTime: " << event.getTime()
       << "\nName: " << event.getName() << endl << endl;
    return os;
}

istream& operator>>(istream& is, Event& event) {
    cout << "Enter Event details: \n";

    cout << "Date (DD-MM-YYYY): ";
    is >> event.date;
    if (!event.isValidDate(event.date)) {
        is.setstate(ios::failbit);
        return is;
    }

    cout << "Time (23:59): ";
    is >> event.time;
    if (!event.isValidTime(event.time)) {
        is.setstate(ios::failbit);
        return is;
    }

    cout << "Event name: ";
    char buffer[256]; // Assuming a reasonable maximum length for the name
    is >> buffer;
    delete[] event.name; // Release the existing memory
    event.name = new char[strlen(buffer) + 1];
    strcpy(event.name, buffer);

    return is;
}