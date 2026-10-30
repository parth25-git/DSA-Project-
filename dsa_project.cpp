#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX_TICKETS 10
#define TOTAL_STATIONS 10

struct Passenger {
    string name;
    int from, to;
};

queue<Passenger> q;

int ticket_booked_count = 0;
int total_fare = 0;

string stations[TOTAL_STATIONS] = {
    "Pune", "Lonavala", "Karjat", "Kalyan", "Thane",
    "Dadar", "Mumbai", "Nashik", "Manmad", "Nagpur"
};

// Read valid station number
int read_station(string message) {
    int number;

    while (true) {
        cout << message;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (number >= 1 && number <= TOTAL_STATIONS) {
            return number;
        }

        cout << "Invalid station number (1-"
             << TOTAL_STATIONS << ")" << endl;
    }
}

// Add passenger to queue
void add_in_queue() {
    Passenger p;

    cout << "Enter passenger name: ";
    cin.ignore();
    getline(cin, p.name);

    p.from = read_station("Enter source station number: ");
    p.to = read_station("Enter destination station number: ");

    if (p.from == p.to) {
        cout << "Source and destination cannot be same" << endl;
        return;
    }

    q.push(p);

    cout << "Successfully added passenger to queue" << endl;
}

// Book ticket
void book_ticket() {
    if (ticket_booked_count == MAX_TICKETS) {
        cout << "No availability of tickets" << endl;
        return;
    }

    if (q.empty()) {
        cout << "No passenger is present in the queue" << endl;
        return;
    }

    Passenger p = q.front();

    int stops = p.from - p.to;

    if (stops < 0)
        stops = -stops;

    int fare = 50 + 20 * (stops - 1);

    cout << p.name << " booked the train ticket" << endl;
    cout << stations[p.from - 1] << " to "
         << stations[p.to - 1] << endl;

    cout << "Stops: " << stops
         << "  Fare: Rs " << fare << endl;

    q.pop();

    ticket_booked_count++;
    total_fare += fare;
}

// Display ticket status
void ticket_status() {
    cout << "Available Tickets: "
         << MAX_TICKETS - ticket_booked_count
         << "/" << MAX_TICKETS << endl;

    cout << "Waiting Count: " << q.size() << endl;

    cout << "Total Money Collected: Rs "
         << total_fare << endl;
}

// Display waiting list
void waiting_list() {
    if (q.empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Waiting List:" << endl;

    queue<Passenger> temp = q;
    int i = 1;

    while (!temp.empty()) {
        cout << i << ". " << temp.front().name
             << " (" << stations[temp.front().from - 1]
             << " to " << stations[temp.front().to - 1]
             << ")" << endl;

        temp.pop();
        i++;
    }
}

// Display all stations
void show_stations() {
    cout << "Available Train Stations:" << endl;

    for (int i = 0; i < TOTAL_STATIONS; i++) {
        cout << i + 1 << ". " << stations[i] << endl;
    }
}

// Main function
int main() {
    int choice, ch1;

    do {
        cout << "\nTrain Ticket Booking System" << endl;
        cout << "1. Add passenger in queue" << endl;
        cout << "2. Book the ticket" << endl;
        cout << "3. Availability of tickets" << endl;
        cout << "4. Waiting list" << endl;
        cout << "5. View stations" << endl;
        cout << "6. Exit" << endl;

        cout << "Select the operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_in_queue();
                break;

            case 2:
                book_ticket();
                break;

            case 3:
                ticket_status();
                break;

            case 4:
                waiting_list();
                break;

            case 5:
                show_stations();
                break;

            case 6:
                cout << "Closing system..." << endl;
                return 0;

            default:
                cout << "Invalid Input" << endl;
        }

        cout << "\nPress 1 to continue / Press 0 to close: ";
        cin >> ch1;

    } while (ch1 == 1);

    cout << "Closing system..." << endl;

    return 0;
}