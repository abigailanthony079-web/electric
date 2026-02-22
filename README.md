# Electrical Load Monitoring System

## Project Description
A C++ console application for monitoring electrical loads and calculating electricity billing for households or small facilities.

## Features Implemented

### Phase 1 (Current)
- ✅ Appliance class with power rating and usage hours
- ✅ Register new appliances with validation
- ✅ View all registered appliances
- ✅ Menu-driven console interface
- ✅ Input validation for all fields

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
5. Select option 3 to exit

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

### Phase 2 (Upcoming)
- Energy calculation logic
- Enhanced menu system
- Multiple appliance management

### Phase 3 (Upcoming)
- Billing calculation
- Load and billing summaries
- Enhanced validation

### Phase 4 (Upcoming)
- File saving and loading
- Code refactoring
- Final testing

## Author
[Your Name]

## License
Educational Project
