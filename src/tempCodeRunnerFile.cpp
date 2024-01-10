case '1': {
                try {
                    Ticket tk;
                    cout << "\nEnter Ticket details \n";
                    cin >> tk;
                    ticketList.push_back(tk);
                    cout << "Ticket Details:\n" << tk;

                    if (ticket.getIsValid()) {
                        cout << "Valid Ticket Details:\n" << tk;
                    } else {
                        cout << "Invalid Ticket Details. Default values used.\n";
                    }
                    tk.writeFile();
                    tk.deleteTicket();
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << endl;
                    cout << "Please run the program again and provide valid input.\n";
                }
                break;