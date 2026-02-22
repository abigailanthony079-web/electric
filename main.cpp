#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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

    // Calculate energy consumption in kWh
    double calculateEnergy() const {
        return (powerRating * usageHours) / 1000.0;  // Convert W to kW
    }

    // Display appliance details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Daily Usage: " << usageHours << " hours" << endl;
        cout << "Energy Consumption: " << calculateEnergy() << " kWh/day" << endl;
        cout << "------------------------" << endl;
    }
};

// Global vector to store appliances
vector<Appliance> appliances;

// Global tariff rate (per kWh)
double tariffRate = 0.0;

// Function prototypes
void registerAppliance();
void viewAllAppliances();
void searchAppliance();
void calculateTotalEnergy();
void setTariffRate();
void calculateBilling();
void displayBillingSummary();
void saveAppliancesToFile();
void loadAppliancesFromFile();
void saveBillingSummaryToFile();
void displayMenu();

int main() {
    int choice;
    
    cout << "=== Electrical Load Monitoring System ===" << endl;
    
    // Load existing appliances from file at startup
    loadAppliancesFromFile();
    
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
                searchAppliance();
                break;
            case 4:
                calculateTotalEnergy();
                break;
            case 5:
                setTariffRate();
                break;
            case 6:
                calculateBilling();
                break;
            case 7:
                displayBillingSummary();
                break;
            case 8:
                saveAppliancesToFile();
                break;
            case 9:
                saveBillingSummaryToFile();
                break;
            case 10:
                cout << "Saving data and exiting program. Goodbye!" << endl;
                saveAppliancesToFile();
                return 0;
            default:
                cout << "Invalid choice! Please select 1-10." << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

void displayMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Register Appliance" << endl;
    cout << "2. View All Appliances" << endl;
    cout << "3. Search Appliance by Name" << endl;
    cout << "4. Calculate Total Energy Consumption" << endl;
    cout << "5. Set Electricity Tariff Rate" << endl;
    cout << "6. Calculate Billing" << endl;
    cout << "7. Display Detailed Billing Summary" << endl;
    cout << "8. Save Appliances to File" << endl;
    cout << "9. Save Billing Summary to File" << endl;
    cout << "10. Exit" << endl;
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


void searchAppliance() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    string searchName;
    cin.ignore();
    
    cout << "\nEnter appliance name to search: ";
    getline(cin, searchName);
    
    bool found = false;
    for (size_t i = 0; i < appliances.size(); i++) {
        if (appliances[i].getName() == searchName) {
            cout << "\n=== Appliance Found ===" << endl;
            appliances[i].display();
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Appliance '" << searchName << "' not found." << endl;
    }
}

void calculateTotalEnergy() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    double totalEnergy = 0.0;
    
    cout << "\n=== Energy Consumption Summary ===" << endl;
    for (size_t i = 0; i < appliances.size(); i++) {
        double energy = appliances[i].calculateEnergy();
        totalEnergy += energy;
        cout << appliances[i].getName() << ": " << energy << " kWh/day" << endl;
    }
    
    cout << "\n--- Total Energy Consumption ---" << endl;
    cout << "Daily: " << totalEnergy << " kWh" << endl;
    cout << "Monthly (30 days): " << totalEnergy * 30 << " kWh" << endl;
    cout << "Yearly (365 days): " << totalEnergy * 365 << " kWh" << endl;
}


void setTariffRate() {
    double rate;
    
    cout << "\nEnter electricity tariff rate (per kWh): ";
    cin >> rate;
    
    if (cin.fail() || rate <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Tariff rate must be a positive value!" << endl;
        return;
    }
    
    tariffRate = rate;
    cout << "Tariff rate set to " << tariffRate << " per kWh" << endl;
}

void calculateBilling() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    if (tariffRate <= 0) {
        cout << "\nPlease set the tariff rate first (Option 5)." << endl;
        return;
    }
    
    double totalEnergy = 0.0;
    for (size_t i = 0; i < appliances.size(); i++) {
        totalEnergy += appliances[i].calculateEnergy();
    }
    
    double dailyCost = totalEnergy * tariffRate;
    double monthlyCost = dailyCost * 30;
    double yearlyCost = dailyCost * 365;
    
    cout << "\n=== Billing Calculation ===" << endl;
    cout << "Tariff Rate: " << tariffRate << " per kWh" << endl;
    cout << "Total Daily Energy: " << totalEnergy << " kWh" << endl;
    cout << "\n--- Electricity Costs ---" << endl;
    cout << "Daily Cost: " << dailyCost << endl;
    cout << "Monthly Cost (30 days): " << monthlyCost << endl;
    cout << "Yearly Cost (365 days): " << yearlyCost << endl;
}

void displayBillingSummary() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    if (tariffRate <= 0) {
        cout << "\nPlease set the tariff rate first (Option 5)." << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "    DETAILED BILLING SUMMARY" << endl;
    cout << "========================================" << endl;
    cout << "Tariff Rate: " << tariffRate << " per kWh" << endl;
    cout << "----------------------------------------" << endl;
    
    double totalEnergy = 0.0;
    
    for (size_t i = 0; i < appliances.size(); i++) {
        double energy = appliances[i].calculateEnergy();
        double cost = energy * tariffRate;
        totalEnergy += energy;
        
        cout << "\nAppliance #" << (i + 1) << ": " << appliances[i].getName() << endl;
        cout << "  Power: " << appliances[i].getPowerRating() << " W" << endl;
        cout << "  Usage: " << appliances[i].getUsageHours() << " hours/day" << endl;
        cout << "  Energy: " << energy << " kWh/day" << endl;
        cout << "  Daily Cost: " << cost << endl;
        cout << "  Monthly Cost: " << cost * 30 << endl;
    }
    
    double totalDailyCost = totalEnergy * tariffRate;
    
    cout << "\n========================================" << endl;
    cout << "TOTAL CONSUMPTION & COST" << endl;
    cout << "========================================" << endl;
    cout << "Total Daily Energy: " << totalEnergy << " kWh" << endl;
    cout << "Total Daily Cost: " << totalDailyCost << endl;
    cout << "Total Monthly Cost: " << totalDailyCost * 30 << endl;
    cout << "Total Yearly Cost: " << totalDailyCost * 365 << endl;
    cout << "========================================" << endl;
}


void saveAppliancesToFile() {
    ofstream outFile("appliances.txt");
    
    if (!outFile) {
        cout << "Error: Unable to open file for writing!" << endl;
        return;
    }
    
    // Save tariff rate first
    outFile << tariffRate << endl;
    
    // Save number of appliances
    outFile << appliances.size() << endl;
    
    // Save each appliance data
    for (size_t i = 0; i < appliances.size(); i++) {
        outFile << appliances[i].getName() << endl;
        outFile << appliances[i].getPowerRating() << endl;
        outFile << appliances[i].getUsageHours() << endl;
    }
    
    outFile.close();
    cout << "Appliances saved successfully to appliances.txt" << endl;
}

void loadAppliancesFromFile() {
    ifstream inFile("appliances.txt");
    
    if (!inFile) {
        cout << "No previous data found. Starting fresh." << endl;
        return;
    }
    
    // Load tariff rate
    inFile >> tariffRate;
    inFile.ignore(); // Ignore newline
    
    // Load number of appliances
    int count;
    inFile >> count;
    inFile.ignore(); // Ignore newline
    
    // Load each appliance
    for (int i = 0; i < count; i++) {
        string name;
        double power, hours;
        
        getline(inFile, name);
        inFile >> power;
        inFile >> hours;
        inFile.ignore(); // Ignore newline
        
        Appliance app(name, power, hours);
        appliances.push_back(app);
    }
    
    inFile.close();
    cout << "Loaded " << count << " appliance(s) from file." << endl;
    if (tariffRate > 0) {
        cout << "Tariff rate: " << tariffRate << " per kWh" << endl;
    }
}

void saveBillingSummaryToFile() {
    if (appliances.empty()) {
        cout << "\nNo appliances registered yet." << endl;
        return;
    }
    
    if (tariffRate <= 0) {
        cout << "\nPlease set the tariff rate first (Option 5)." << endl;
        return;
    }
    
    ofstream outFile("billing_summary.txt");
    
    if (!outFile) {
        cout << "Error: Unable to open file for writing!" << endl;
        return;
    }
    
    outFile << "========================================" << endl;
    outFile << "    DETAILED BILLING SUMMARY" << endl;
    outFile << "========================================" << endl;
    outFile << "Tariff Rate: " << tariffRate << " per kWh" << endl;
    outFile << "----------------------------------------" << endl;
    
    double totalEnergy = 0.0;
    
    for (size_t i = 0; i < appliances.size(); i++) {
        double energy = appliances[i].calculateEnergy();
        double cost = energy * tariffRate;
        totalEnergy += energy;
        
        outFile << "\nAppliance #" << (i + 1) << ": " << appliances[i].getName() << endl;
        outFile << "  Power: " << appliances[i].getPowerRating() << " W" << endl;
        outFile << "  Usage: " << appliances[i].getUsageHours() << " hours/day" << endl;
        outFile << "  Energy: " << fixed << setprecision(2) << energy << " kWh/day" << endl;
        outFile << "  Daily Cost: " << fixed << setprecision(2) << cost << endl;
        outFile << "  Monthly Cost: " << fixed << setprecision(2) << cost * 30 << endl;
    }
    
    double totalDailyCost = totalEnergy * tariffRate;
    
    outFile << "\n========================================" << endl;
    outFile << "TOTAL CONSUMPTION & COST" << endl;
    outFile << "========================================" << endl;
    outFile << "Total Daily Energy: " << fixed << setprecision(2) << totalEnergy << " kWh" << endl;
    outFile << "Total Daily Cost: " << fixed << setprecision(2) << totalDailyCost << endl;
    outFile << "Total Monthly Cost: " << fixed << setprecision(2) << totalDailyCost * 30 << endl;
    outFile << "Total Yearly Cost: " << fixed << setprecision(2) << totalDailyCost * 365 << endl;
    outFile << "========================================" << endl;
    
    outFile.close();
    cout << "Billing summary saved successfully to billing_summary.txt" << endl;
}
