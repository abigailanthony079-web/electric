# Electrical Load Monitoring System

## Project Description
A C++ console application for monitoring electrical loads and calculating electricity billing for households or small facilities.

## Features Implemented

### Phase 1 ✅
- ✅ Appliance class with power rating and usage hours
- ✅ Register new appliances with validation
- ✅ View all registered appliances
- ✅ Menu-driven console interface
- ✅ Input validation for all fields

### Phase 2 (Current) ✅
- ✅ Energy calculation logic (kWh)
- ✅ Search appliance by name
- ✅ Calculate total energy consumption
- ✅ Display daily, monthly, and yearly energy totals
- ✅ Enhanced menu system

## How to Compile and Run

### Windows (using g++)
```bash
g++ main.cpp -o electrical_monitor.exe
./electrical_monitor.exe
```

### Alternative (using MinGW)
```bash
g++ -o electrical_monitor main.cpp
electrical_monitor.exe
```

## Usage Instructions

1. Run the program (data loads automatically from appliances.txt if it exists)
2. Select option 1 to register an appliance
3. Select option 2 to view all registered appliances
4. Select option 3 to search for a specific appliance by name
5. Select option 4 to calculate total energy consumption (daily, monthly, yearly)
6. Select option 5 to set the electricity tariff rate (per kWh)
7. Select option 6 to calculate billing costs
8. Select option 7 to display detailed billing summary with per-appliance breakdown
9. Select option 8 to manually save appliances to file
10. Select option 9 to save billing summary to file
11. Select option 10 to exit (automatically saves data)

## Data Validation
- Appliance name cannot be empty
- Power rating must be greater than 0
- Usage hours must be between 0 and 24
- Invalid menu choices are handled gracefully

## Project Structure
```
electrical-load-monitoring/
├── main.cpp              # Main program file
├── README.md             # Project documentation
├── readme                # Assignment requirements
├── appliances.txt        # Saved appliance data (auto-generated)
└── billing_summary.txt   # Saved billing reports (auto-generated)
```

## Development Timeline

### Phase 1 ✅
- Created GitHub repository and project structure
- Implemented Appliance class
- Register and view appliances functionality
- Input validation

### Phase 2 ✅
- ✅ Energy calculation logic (kWh)
- ✅ Search appliance by name
- ✅ Calculate total energy consumption
- ✅ Display daily, monthly, and yearly energy totals
- ✅ Enhanced menu system

### Phase 3 ✅
- ✅ Set electricity tariff rate
- ✅ Calculate billing costs
- ✅ Display detailed billing summary
- ✅ Per-appliance cost breakdown
- ✅ Enhanced input validation

### Phase 4 (Current) ✅
- ✅ Save appliances to file (appliances.txt)
- ✅ Load appliances automatically on startup
- ✅ Save billing summary to file (billing_summary.txt)
- ✅ Persistent data storage with fstream
- ✅ Auto-save on exit

### Phase 3 ✅
- ✅ Set electricity tariff rate
- ✅ Calculate billing costs
- ✅ Display detailed billing summary
- ✅ Per-appliance cost breakdown
- ✅ Enhanced input validation

### Phase 4 ✅
- ✅ Save appliances to file (appliances.txt)
- ✅ Load appliances automatically on startup
- ✅ Save billing summary to file (billing_summary.txt)
- ✅ Persistent data storage with fstream
- ✅ Auto-save on exit
- ✅ Code refactoring and final testing

## Author
[Your Name]

## License
Educational Project
