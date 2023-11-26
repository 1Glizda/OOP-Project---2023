#include <iostream>
#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"

using namespace std;


int main() {
    //part of generating random integer function
    srand(static_cast<unsigned>(time(nullptr)));

    //object creating and testing 
    Event e;
    Event e2("12-12-2002", "23:30", "bOb");
    e.showObject();
    e2.showObject();
    EventLocation el;
    EventLocation el2(-32, 8, South);
    EventLocation el3(5, 3, South);
    el.showObject();
    el2.showObject();
    el3.showObject();
    Ticket t;
    Ticket t1 (0, 0, "Acasa" , 3);
    Ticket t2 (3, 2, "BT Arena" , 3);
    t.showObject();
    t1.showObject();
    t2.showObject();

    //cin inputs for the objects
    try {
        Ticket ticket;
        cout << "Enter Ticket details (Is Valid, Is VIP, District, Validity): ";
        cin >> ticket;
        cout << "Ticket Details:\n" << ticket;

        if (ticket.getIsValid()) {
            cout << "Valid Ticket Details:\n" << ticket;
        } else {
            cout << "Invalid Ticket Details. Default values used.\n";
        }
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        cout << "Please run the program again and provide valid input.\n";
    };

    try {
        EventLocation location;
        cin >> location;
        cout << "Event Location details:\n" << location;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        cout << "Please run the program again and provide valid input.\n";
    }

    try {
        Event event;
        cin >> event;
        cout << "\nEvent Details:\n" << event;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        cout << "Please run the program again and provide valid input.\n";
    }

    return 0;
}