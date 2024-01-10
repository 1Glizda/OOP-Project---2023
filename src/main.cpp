#include <iostream>
#include <fstream>
#include <vector>
#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"

using namespace std;

vector<Ticket> ticketList;
vector<EventLocation> eventLocationList;
vector<Event> eventList;

bool fileExists(const string& filename) {
    ifstream file(filename.c_str());
    return file.good();
}

int main() {
    //part of generating random integer function
    srand(static_cast<unsigned>(time(nullptr)));

    //object creating and testing 
    Event e;
    Event e1("12-12-2002", "23:30", "bOb");
    // e.showObject();
    // e1.showObject();
    e.deleteEvent();
    e1.deleteEvent();

    EventLocation el;
    EventLocation el2(-32, 8, South);
    EventLocation el3(5, 3, South);
    // el.showObject();
    // el2.showObject();
    // el3.showObject();
    el.deleteEventLocation();
    el2.deleteEventLocation();
    el3.deleteEventLocation();

    Ticket t;
    Ticket t1(0, 0, "Acasa", 3);
    Ticket t2(3, 2, "BT Arena", 3);
    // t.showObject();
    // t1.showObject();
    // t2.showObject();
    t.deleteTicket();
    t1.deleteTicket();
    t2.deleteTicket();

    Event event;
    EventLocation location;
    Ticket ticket;
    if (fileExists("Ticket.dat")) {
        ticket.readBinaryFile(ticketList);
    };

    //cin inputs for the objects, with a terminal menu
    char choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Add Ticket\n";
        cout << "2. Add Event Location\n";
        cout << "3. Add Event\n";
        cout << "4. Show All Tickets\n";
        cout << "5. Show All Event Locations\n";
        cout << "6. Show All Events\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice (1-7): ";
        cin >> choice;
        cout << "\n";

         switch (choice) {
            case '1': {
                try {
                    Ticket tk;
                    cout << "\nEnter Ticket details \n";
                    cin >> tk;
                    ticketList.push_back(tk);
                    if (!ticket.getIsValid()) {
                        cout << "Invalid Ticket Details. Default values used.\n";
                    }
                    tk.writeFile();
                    tk.deleteTicket();
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;
            }
            case '2': {
                try {
                    cin >> location;
                    eventLocationList.push_back(location);
                    cout << "\nEvent Location details:\n" << location;
                    location.writeTextFile();
                    location.deleteEventLocation();
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;
            }
            case '3': {
                try {
                    cin >> event;
                    eventList.push_back(event);
                    cout << "\nEvent Details:\n" << event;
                    event.writeTextFile();
                    event.deleteEvent();
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;
            }
            case '4':
                ticket.readBinaryFile(ticketList);
                break;
            case '5':
                location.readTextFile(eventLocationList);
                break;
            case '6':
                event.readTextFile(eventList);
                break;
            case '7':
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 7.\n";
        }

        cout << "\nDo you want to add another object or show all objects? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // ticket.deleteTicket();
    // location.deleteEventLocation();
    // event.deleteEvent();

    return 0;
}

