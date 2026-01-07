#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int type, distance, age, day, hour, bag;
    char ccode, student, member;

    cout << "Select transport type (1 = Bus, 2 = Train, 3 = Flight): ";
    cin >> type;

    cout << "Enter travel distance: ";
    cin >> distance;

    cout << "Enter passenger age: ";
    cin >> age;

    cout << "Day (1 = Weekday, 2 = Weekend): ";
    cin >> day;

    cout << "Class code (s = Sleeper, a = AC, b = Business, n = Normal): ";
    cin >> ccode;

    cout << "Baggage weight (kg): ";
    cin >> bag;

    cout << "Student? (y/n): ";
    cin >> student;

    cout << "Member? (y/n): ";
    cin >> member;

    cout << "Travel hour (0–23): ";
    cin >> hour;

    double fare = 0, surcharge = 0, discount = 0;
    double bag_fee = 0, total_fare = 0;

    switch (type) {
    case 1: // Bus
        fare = distance * 0.5;
        if (ccode == 's') fare *= 1.2; // Sleeper
        if (hour >= 4 && hour <= 7) surcharge = fare * 0.2; // Peak hours
        else surcharge = fare * 0.1;

        if (age <= 11) discount = fare * 0.5;
        else if (age >= 60) discount = fare * 0.3;
        else if (student == 'y' || student == 'Y') discount = fare * 0.1;
        break;

    case 2: // Train
        fare = distance * 0.3;
        if (ccode == 'a') fare *= 1.15; // AC
        else if (ccode == 'b') fare *= 1.5; // Business

        if (hour >= 18 && hour <= 22) surcharge = fare * 0.1;

        if (age < 12) fare /= 2; // Minimum fare
        if (member == 'y' || member == 'Y') discount += fare * 0.3;
        if (age >= 60) discount += fare * 0.25;
        break;

    case 3: // Flight
        fare = distance * 0.5;
        if (ccode == 'b') fare *= 1.15; // Business class

        if (bag > 10) bag_fee = (bag - 10) * 1.5;

        if (student == 'y' || student == 'Y') discount += fare * 0.15;
        if (member == 'y' || member == 'Y') discount += fare * 0.05;
        if (fare <= 15) discount += fare * 0.05;
        if (age >= 60) discount += fare * 0.10;
        break;

    default:
        cout << "Invalid transport type\n";
        return 0;
    }

    total_fare = fare + surcharge + bag_fee - discount;

    cout << fixed << setprecision(2);
    cout << "\n--- Ticket Summary ---\n";
    cout << "Base Fare: $" << fare << endl;
    cout << "Surcharge: $" << surcharge << endl;
    cout << "Baggage Fee: $" << bag_fee << endl;
    cout << "Discount: -$" << discount << endl;
    cout << "Final Ticket Price: $" << total_fare << endl;

    return 0;
}
