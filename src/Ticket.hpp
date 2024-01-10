#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Ticket {
    const int ticketId;
    int ticketid;
    bool isValid;
    bool isVIP;
    string district;
    int validity;

    int genRandomNumber() {
        return rand();
    }

    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);
    friend ifstream& operator>>(ifstream& ifs, Ticket& ticket);

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

     void writeFile() {
        // ofstream txt_f("Ticket.txt", ios::app);

        // txt_f << this->ticketId << "\n";
        // txt_f << this->isValid << "\n";
        // txt_f << this->isVIP << "\n";
        // txt_f << this->district << "\n";
        // txt_f << this->validity << "\n\n";
        ofstream f("Ticket.dat", ios::binary | ios::app);

        f.write((char*)&this->ticketId, sizeof(this->ticketId));
        f.write((char*)&this->isValid, sizeof(this->isValid));
        f.write((char*)&this->isVIP, sizeof(this->isVIP));

        int districtLength = this->district.length();
        f.write((char*)&districtLength, sizeof(districtLength));
        f.write(this->district.c_str(), districtLength);

        f.write((char*)&this->validity, sizeof(this->validity));

        // txt_f.close();
        f.close();
        cout << "Binary file written successfully.\n";
    }

    // void readTextFile(vector<Ticket>& tickets) {
    //     ifstream txt_f("Ticket.txt");

    //     while (!txt_f.eof()) {
    //         while (txt_f >> ticketid >> isValid >> isVIP) {
    //             txt_f.ignore(numeric_limits<streamsize>::max(), '\n');  // Skip newline
    //             getline(txt_f, district);
    //             txt_f >> validity;

    //             Ticket t(isValid, isVIP, district, validity);
    //             t.ticketid = ticketid;  // Set the ticket ID from the file

    //             cout << t;
    //             tickets.push_back(t);
    //         }
    //     }

    //     txt_f.close();
    //     cout << "Text file read successfully.\n";
    // }

    void readBinaryFile(vector<Ticket>& tickets) {
    ifstream f("Ticket.dat", ios::binary);

    while (true) {
        Ticket ticket;

        if (!f.read((char*)&ticket.ticketid, sizeof(ticket.ticketid))) {
            break; // Reached end of file
        }

        f.read((char*)&ticket.isValid, sizeof(ticket.isValid));
        f.read((char*)&ticket.isVIP, sizeof(ticket.isVIP));

        int districtLength;
        f.read((char*)&districtLength, sizeof(districtLength));

        char buffer[districtLength + 1];
        f.read(buffer, districtLength);
        buffer[districtLength] = '\0';
        ticket.district = buffer;

        f.read((char*)&ticket.validity, sizeof(ticket.validity));


        cout << ticket; // this will show all the previous created tickets, but all the previous will have
        tickets.push_back(ticket);
    }

    f.close();

    cout << "Binary file read successfully.\n\n";
    }


    int getTicketId() const {
        return ticketId;
    }

    int getTicketid() const {
        return ticketid;
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

    while (true) {
        cout << "Is Valid (1 for true, 0 for false): ";
        is >> ticket.isValid;

        if (is.fail()) {
            cerr << "Invalid input. Please enter a valid integer.\n";
            is.clear(); 
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (ticket.isValid != 0 && ticket.isValid != 1) {
            cerr << "Invalid input. Please enter 0 or 1.\n";
            is.clear(); 
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Valid input, break out of the loop
            break;
        }
    }



    if (ticket.isValid) {
        while (true) {
            cout << "Is VIP (1 for true, 0 for false): ";
            is >> ticket.isVIP;

            if (is.fail()) {
            cerr << "Invalid input. Please enter a valid integer.\n";
            is.clear(); 
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (ticket.isVIP != 0 && ticket.isVIP != 1) {
            cerr << "Invalid input. Please enter 0 or 1.\n";
            is.clear(); 
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Valid input, break out of the loop
            break;
        }}


        do {
        cout << "District (string, ex. 'Floor'): ";
        is.ignore();
        getline(is, ticket.district);

        if (ticket.district.empty()) {
            cerr << "Invalid input. Please try again.\n";
            is.clear();  
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (ticket.district.empty());

        do {
        cout << "Validity (integer, ex. '3' (days) ): ";
        is >> ticket.validity;

        if (ticket.validity <= 0) {
            cerr << "Invalid input. Please try again.\n";
            is.clear();  
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        } while (ticket.validity <= 0);
    } else {
        ticket.isVIP = false;
        ticket.district = "none";
        ticket.validity = 0;
    }

    return is;
}

ostream& operator<<(ostream& os, const Ticket& ticket) {
    if (ticket.ticketid == 0) {
    os << "Ticket id: " << ticket.getTicketId()
       << "\nIs valid: " << (ticket.getIsValid() ? "true" : "false")
       << "\nIs vip: " << (ticket.getIsVIP() ? "true" : "false")
       << "\nDistrict: " << ticket.getDistrict()
       << "\nDays valid: " << ticket.getValidity() << endl << endl;
    return os;
    } else {
    os << "Ticket id: " << ticket.getTicketid()
       << "\nIs valid: " << (ticket.getIsValid() ? "true" : "false")
       << "\nIs vip: " << (ticket.getIsVIP() ? "true" : "false")
       << "\nDistrict: " << ticket.getDistrict()
       << "\nDays valid: " << ticket.getValidity() << endl << endl;
    return os;    
    }
}
