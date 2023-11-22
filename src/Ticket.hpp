#include <iostream>
#include <string>

using namespace std;

class Ticket {
    const int ticketId;
    bool isValid;
    bool isVIP;
    string district;
    int validity;

public:
    int genRandomNumber() {
	    srand((unsigned) time(NULL));
	    int random = rand();
	    return random;
    }
     Ticket() : ticketId(genRandomNumber()){
        this->isValid = true;
        this->isVIP = false;
        this->district = "at home";
        this->validity = 1;
     };

     void showObject() {
        cout << "Ticket id: " << ticketId << "\nIs valid: " << isValid << "\nIs vip? " << isVIP << "\nAt what district? " << district << "\nHow many days is it valid? " << validity << endl << endl;
            }

};