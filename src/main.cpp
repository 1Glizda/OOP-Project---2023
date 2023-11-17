#include <iostream>
#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"

using namespace std;


int main() {
    cout << "hello world" << endl << endl;
    Event e;
    Event e2("12-06-2002", "15:00", "bOb");
    e.showObject();
    e2.showObject();
    EventLocation el;
    EventLocation el2(32, 8, Nord, 4);
    el.showObject();
    el2.showObject();

    return 0;
}