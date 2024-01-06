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
    Event e1("12-12-2002", "23:30", "bOb");
    e.showObject();
    e1.showObject();
    e.deleteEvent();
    e1.deleteEvent();

    EventLocation el;
    EventLocation el2(-32, 8, South);
    EventLocation el3(5, 3, South);
    el.showObject();
    el2.showObject();
    el3.showObject();
    el.deleteEventLocation();
    el2.deleteEventLocation();
    el3.deleteEventLocation();

    Ticket t;
    Ticket t1(0, 0, "Acasa", 3);
    Ticket t2(3, 2, "BT Arena", 3);
    t.showObject();
    t1.showObject();
    t2.showObject();
    t.deleteTicket();
    t1.deleteTicket();
    t2.deleteTicket();

    //cin inputs for the objects, with a terminal menu
    char choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Add Ticket\n";
        cout << "2. Add Event Location\n";
        cout << "3. Add Event\n";
        cout << "4. Exit\n";

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1': {
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
                }
                break;
            }
            case '2': {
                try {
                    EventLocation location;
                    cin >> location;
                    cout << "\nEvent Location details:\n" << location;
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;
            }
            case '3': {
                try {
                    Event event;
                    cin >> event;
                    cout << "\nEvent Details:\n" << event;
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;
            }
            case '4':
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }

        cout << "Do you want to add another object? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}