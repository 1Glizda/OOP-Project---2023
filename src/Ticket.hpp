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

     void showObject() {
        cout << "Ticket id: " << ticketId << "\nIs valid: " << isValid << "\nIs vip: " << isVIP << "\nDistrict: " 
        << district << "\nDays valid: " << validity << endl << endl;
            }

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
};
