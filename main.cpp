#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Appliance class to represent electrical appliances
class Appliance {
private:
    string name;
    double powerRating;  // in watts
    double usageHours;   // daily usage in hours

public:
    // Constructor
    Appliance(string n, double power, double hours) {
        name = n;
        powerRating = power;
        usageHours = hours;
    }

    // Getters
    string getName() const { return name; }
    double getPowerRating() const { return powerRating; }
    double getUsageHours() const { return usageHours; }

    // Display appliance details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Daily Usage: " << usageHours << " hours" << endl;
        cout << "------------------------" << endl;
    }
};

// Global vector to store appliances
vector<Appliance> appliances;

// Function prototypes
void registerAppliance();
void viewAllAppliances();
void displayMenu();

int main() {
    int choice;
    
    cout << "=== Electrical Load Monitoring System ===" << endl;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        
        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                registerAppliance();
                break;
            case 2:
                viewAllAppliances();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please select 1-3." << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

void displayMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Register Appliance" << endl;
    cout << "2. View All Appliances" << endl;
    cout << "3. Exit" << endl;
}

void registerAppliance() {
    string name;
    double power, hours;
    
    cin.ignore(); // Clear input buffer
    
    // Get appliance name
    cout << "\nEnter appliance name: ";
    getline(cin, name);
    
    // Validate name
    if (name.empty()) {
        cout << "Error: Appliance name cannot be empty!" << endl;
        return;
    }
    
    // Get power rating
    cout << "Enter power rating (watts): ";
    cin >> power;
    
    if (cin.fail() || power <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Power rating must be greater than zero!" << endl;
        return;
    }
    
    // Get usage hours
    cout << "Enter daily usage (hours): ";
    cin >> hours;
    
    if (cin.fail() || hours < 0 || hours > 24) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Usage hours must be between 0 and 24!" << endl;
        return;
    }
    
    // Create and add appliance
    Appliance newAppliance(name, power, hours);
    appliances.push_back(newAppliance);
    
    cout << "Appliance registered successfully!" << endl;
}

void viewAllAppliances() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    cout << "\n=== Registered Appliances ===" << endl;
    for (size_t i = 0; i < appliances.size(); i++) {
        cout << "\nAppliance #" << (i + 1) << endl;
        appliances[i].display();
    }
}
