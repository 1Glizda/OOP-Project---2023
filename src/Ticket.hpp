#include <iostream>
#include <string>

using namespace std;

class Ticket {
    const int ticketId;
    bool isValid;
    bool isVIP;
    string district;
    int validity;

    int genRandomNumber() {
        return rand();
    }

    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);

public:
     Ticket() : ticketId(genRandomNumber()){
        this->isValid = true;
        this->isVIP = false;
        this->district = "at home";
        this->validity = 1;
     };

     Ticket(bool IsValid, bool IsVip, string District, int Validity) : ticketId(genRandomNumber()) {
        this->isValid = IsValid;
        this->isVIP = IsVip;
        this->district = District;
        if(IsValid == true) {
            if(Validity > 0) {
            this->validity = Validity;
            } else {
                this->validity = 1;
            }
        } else {
            this->validity = 0;
            this->isVIP = false;
            this->district = "none";
        }
     };


    int getTicketId() const {
        return ticketId;
    }

    bool getIsValid() const {
        return isValid;
    }

    void setIsValid(bool isValid) {
        this->isValid = isValid;
    }

    bool getIsVIP() const {
        return isVIP;
    }

    void setIsVIP(bool isVIP) {
        this->isVIP = isVIP;
    }

    string getDistrict() const {
        return district;
    }

    void setDistrict(const string& district) {
        this->district = district;
    }

    int getValidity() const {
        return validity;
    }

    void setValidity(int validity) {
        if (isValid && validity > 0) {
            this->validity = validity;
        } else {
            this->validity = 1;
        }
    }

    void showObject() {
        cout << "Ticket id: " << ticketId << "\nIs valid: " << isValid << "\nIs vip: " << isVIP << "\nDistrict: " 
        << district << "\nDays valid: " << validity << endl << endl;
    }

     void deleteTicket() {
        isValid = false;
        isVIP = false;
        district = "deleted";
        validity = 0;
    }

    char operator[](size_t index) const {
        if (index < district.size()) {
            return district[index];
        } else {
            return '\0'; // Return null character for out-of-bounds access
        }
    }

    Ticket operator+(const Ticket& other) const {
        Ticket result;
        result.isValid = isValid || other.isValid;
        result.isVIP = isVIP || other.isVIP;
        result.district = district + other.district;
        result.validity = validity + other.validity;
        return result;
    }
};

istream& operator>>(istream& is, Ticket& ticket) {
    cout << "\n";
    cout << "Is Valid (1 for true, 0 for false): ";
    is >> ticket.isValid;
    if (is.fail() || (ticket.isValid != 0 && ticket.isValid != 1)) {
        is.setstate(ios::failbit);
    }

    if (ticket.isValid) {
        cout << "Is VIP (1 for true, 0 for false): ";
        is >> ticket.isVIP;
        if (is.fail() || (ticket.isVIP != 0 && ticket.isVIP != 1)) {
            is.setstate(ios::failbit);
        }

        cout << "District (string, ex. 'Floor'): ";
        is.ignore();
        getline(is, ticket.district);
        if (ticket.district.empty()) {
            is.setstate(ios::failbit);
        }

        cout << "Validity (integer, ex. '3' (days) ): ";
        is >> ticket.validity;
        if (is.fail() || ticket.validity <= 0) {
            is.setstate(ios::failbit);
        }
    } else {
        ticket.isVIP = false;
        ticket.district = "none";
        ticket.validity = 0;
    }

    return is;
}

ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "Ticket id: " << ticket.getTicketId()
       << "\nIs valid: " << (ticket.getIsValid() ? "true" : "false")
       << "\nIs vip: " << (ticket.getIsVIP() ? "true" : "false")
       << "\nDistrict: " << ticket.getDistrict()
       << "\nDays valid: " << ticket.getValidity() << endl << endl;
    return os;
}

