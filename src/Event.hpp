#include <string>
#include <iostream>

using namespace std;


class Event {
    string date;
    string time;
    char* name;

    friend ostream& operator<<(ostream& os, const Event& event);
    friend istream& operator>>(istream& is, Event& event);
    friend ifstream& operator>>(ifstream& ifs, Event& event);

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
        this->name = new char[strlen(Name) + 1];
        strcpy(name, Name);
    }

    void writeTextFile() {
        ofstream txt_f("Event.txt", ios::app);

        txt_f << this->date << "\n";
        txt_f << this->time << "\n";
        txt_f << this->name << "\n";

        txt_f.close();
        cout << "Text file written successfully.\n";
    }

    void readTextFile(vector<Event>& events) {
        ifstream txt_f("Event.txt");

        while (!txt_f.eof()) {
            Event e;
            
            getline(txt_f, e.date);
            getline(txt_f, e.time);
            char buffer[256];
            txt_f.getline(buffer, 256);
            e.setName(buffer);
            cout << e;

            events.push_back(e);
        }

        txt_f.close();
        cout << "Text file read successfully.\n";
    }

    ~Event() {
        delete[] name;
    }

    Event(const Event& other) : date(other.date), time(other.time) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    Event& operator=(const Event& other) {
        if (this != &other) {
            delete[] name;
            date = other.date;
            time = other.time;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
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
        name = new char[strlen("no name") + 1];
        strcpy(name, "no name");
    }

    Event operator--() {
        // Pre-decrement operator
        if (isValidDate(date)) {
            int day = stoi(date.substr(0, 2));
            if (day > 1) {
                date[0] = static_cast<char>((day - 1) / 10 + '0');
                date[1] = static_cast<char>((day - 1) % 10 + '0');
            }
        }
        return *this;
    }

    Event operator--(int) {
        // Post-decrement operator
        Event temp = *this;
        if (isValidDate(date)) {
            int day = stoi(date.substr(0, 2));
            if (day > 1) {
                date[0] = static_cast<char>((day - 1) / 10 + '0');
                date[1] = static_cast<char>((day - 1) % 10 + '0');
            }
        }
        return temp;
    }

    bool operator<(const Event& other) const {
        // Relational operator <
        return date < other.date;
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

    do {
    cout << "Date (DD-MM-YYYY): ";
    is >> event.date;

    if (!event.isValidDate(event.date)) {
        cerr << "Invalid date input. Please try again.\n";
        is.clear();  
        is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (!event.isValidDate(event.date));

    do {
    cout << "Time (23:59): ";
    is >> event.time;
    if (!event.isValidTime(event.time)) {
        cerr << "Invalid time input. Please try again.\n";
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (!event.isValidTime(event.time));

    cout << "Event name: ";
    char buffer[256]; 
    is >> buffer;
    event.setName(buffer);

    return is;
}
