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

1. Run the program
2. Select option 1 to register an appliance
3. Enter appliance details (name, power rating in watts, daily usage in hours)
4. Select option 2 to view all registered appliances
5. Select option 3 to search for a specific appliance by name
6. Select option 4 to calculate total energy consumption (daily, monthly, yearly)
7. Select option 5 to set the electricity tariff rate (per kWh)
8. Select option 6 to calculate billing costs
9. Select option 7 to display detailed billing summary with per-appliance breakdown
10. Select option 8 to exit

## Data Validation
- Appliance name cannot be empty
- Power rating must be greater than 0
- Usage hours must be between 0 and 24
- Invalid menu choices are handled gracefully

## Project Structure
```
electrical-load-monitoring/
├── main.cpp           # Main program file
├── README.md          # Project documentation
└── readme             # Assignment requirements
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

### Phase 3 (Current) ✅
- ✅ Set electricity tariff rate
- ✅ Calculate billing costs
- ✅ Display detailed billing summary
- ✅ Per-appliance cost breakdown
- ✅ Enhanced input validation

### Phase 3 ✅
- ✅ Set electricity tariff rate
- ✅ Calculate billing costs
- ✅ Display detailed billing summary
- ✅ Per-appliance cost breakdown
- ✅ Enhanced input validation

### Phase 4 (Upcoming)
- File saving and loading
- Code refactoring
- Final testing

## Author
[Your Name]

## License
Educational Project
