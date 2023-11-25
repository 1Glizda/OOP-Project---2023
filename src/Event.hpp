#include <string>
#include <iostream>

using namespace std;

class Event {
    string date;
    string time;
    char* name;

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

    void showObject() {
    cout << "This is the date: " << date << "\nThis is the time: " << time << "\nThis is the name: " << name << endl << endl;
}
};