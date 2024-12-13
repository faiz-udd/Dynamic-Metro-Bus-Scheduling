#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// Structure to store station data
struct Station {
    int id;
    int inflow;
    int outflow;
    int netLoad;
};

// Function to calculate net load at each station
void calculateNetLoad(vector<Station> &stations) {
    for (auto &station : stations) {
        station.netLoad = station.inflow - station.outflow;
    }
}

// Function to predict future inflow (simplified for this example)
int predictFutureInflow(int currentInflow) {
    // For simplicity, assume a 10% increase in inflow
    return static_cast<int>(currentInflow * 1.1);
}

// Function to dynamically allocate buses and manage fleet
void manageFleet(vector<Station> &stations, int busCapacity, int baseInterval) {
    queue<int> emergencyBuses; // Queue for emergency bus dispatch

    cout << "Fleet Management Report:\n";
    for (auto &station : stations) {
        int predictedLoad = station.netLoad + predictFutureInflow(station.inflow);

        // Check if inflow exceeds 5x bus capacity
        if (station.inflow > 5 * busCapacity) {
            emergencyBuses.push(station.id);
            cout << "Emergency bus dispatched to Station " << station.id << " due to high inflow.\n";
            continue;
        }

        // Calculate buses needed and adjust interval
        int busesNeeded = ceil(static_cast<double>(predictedLoad) / busCapacity);
        int adjustedInterval = max(1, baseInterval - (busesNeeded - 1)); // Reduce interval for high demand

        cout << "Station " << station.id << ": " << busesNeeded << " buses needed, adjusted interval: " << adjustedInterval << " minutes.\n";
    }

    // Process emergency buses
    while (!emergencyBuses.empty()) {
        int stationId = emergencyBuses.front();
        emergencyBuses.pop();
        cout << "Emergency bus is operating at Station " << stationId << ".\n";
    }
}

int main() {
    // Example data (replace with real-time data in practice)
    vector<Station> stations = {
        {1, 800, 100, 0},
        {2, 150, 100, 0},
        {3, 1000, 200, 0},
        {4, 400, 150, 0},
        {5, 250, 100, 0}
    };

    int busCapacity = 160; // Capacity of each bus
    int baseInterval = 5;  // Base time interval in minutes between buses

    // Step 1: Calculate net load at each station
    calculateNetLoad(stations);

    // Step 2: Manage fleet dynamically
    manageFleet(stations, busCapacity, baseInterval);

    return 0;
}
