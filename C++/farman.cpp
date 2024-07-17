#include <iostream>
#include <string>
#include <limits>

using namespace std;

class CrimeReport {
protected:
    string district;
    string area;
    int num_people;
    string vehicle_type;
    string vehicle_no;
    string description;
    
public:
    CrimeReport() {}
    
    CrimeReport(string dist, string ar) : district(dist), area(ar) {}

    virtual void inputDetails() {
        cout << "\nEnter number of people involved: ";
        cin >> num_people;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to ignore any leftover newline character
        cout << "Enter vehicle type: ";
        getline(cin, vehicle_type);
        cout << "Enter vehicle number: ";
        getline(cin, vehicle_no);
        cout << "Enter description (max 1000 characters): ";
        getline(cin, description);
    }

    virtual void displayDetails() {
        cout << "\n--- Crime Report Details ---\n";
        cout << "District: " << district << endl;
        cout << "Area: " << area << endl;
        cout << "Number of people involved: " << num_people << endl;
        cout << "Vehicle type: " << vehicle_type << endl;
        cout << "Vehicle number: " << vehicle_no << endl;
        cout << "Description: " << description << endl;
    }

    virtual ~CrimeReport() {}
};

class Snatching : public CrimeReport {
    string snatched_item;
public:
    Snatching(string dist, string ar) : CrimeReport(dist, ar) {}

    void inputDetails() override {
        CrimeReport::inputDetails();
        cout << "Enter snatched item: ";
        getline(cin, snatched_item);
    }

    void displayDetails() override {
        CrimeReport::displayDetails();
        cout << "Snatched item: " << snatched_item << endl;
    }
};

class Harassment : public CrimeReport {
    string harassment_type;
    bool is_native;
public:
    Harassment(string dist, string ar) : CrimeReport(dist, ar) {}

    void inputDetails() override {
        CrimeReport::inputDetails();
        cout << "Enter harassment type (physical/verbal): ";
        getline(cin, harassment_type);
        cout << "Was the person native? (1 for Yes, 0 for No): ";
        cin >> is_native;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to ignore any leftover newline character
    }

    void displayDetails() override {
        CrimeReport::displayDetails();
        cout << "Harassment type: " << harassment_type << endl;
        cout << "Is native: " << (is_native ? "Yes" : "No") << endl;
    }
};

class Robbery : public CrimeReport {
    string robbed_item;
public:
    Robbery(string dist, string ar) : CrimeReport(dist, ar) {}

    void inputDetails() override {
        CrimeReport::inputDetails();
        cout << "Enter robbed item: ";
        getline(cin, robbed_item);
    }

    void displayDetails() override {
        CrimeReport::displayDetails();
        cout << "Robbed item: " << robbed_item << endl;
    }
};

void displayMenu() {
    cout << "\n--- Crime Monitoring System ---\n";
    cout << "1. Snatching\n";
    cout << "2. Harassment\n";
    cout << "3. Robbery\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    string district, area;
    int choice;

    cout << "Enter your district: ";
    cin >> district;
    cout << "Enter your area: ";
    cin >> area;

    while (true) {
        displayMenu();
        cin >> choice;

        CrimeReport* report = nullptr;

        switch (choice) {
            case 1:
                report = new Snatching(district, area);
                break;
            case 2:
                report = new Harassment(district, area);
                break;
            case 3:
                report = new Robbery(district, area);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }


        report->inputDetails();
        report->displayDetails();

        delete report;
    }

    return 0;
}