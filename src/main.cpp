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

    return 0;
}