#include <string>
#include <iostream>

using namespace std;

class Event {
    string date;
    string time;
    char* name;

public:
    Event() {
        this->date = "12-12-2012";
        this->time = "00:00";
        this->name = "no name";
    };

    Event(string Date, string Time, char* Name) {
        this->date = Date;
        this->time = Time;
        this->name = new char(strlen(Name) + 1);
        strcpy(name, Name);
    }

    void showObject() {
    cout << "This is the date: " << date << "\nThis is the time: " << time << "\nThis is the name: " << name << endl << endl;
}

};