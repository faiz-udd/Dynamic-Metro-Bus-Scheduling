# Dynamic-Metro-Bus-Scheduling
This is a Dynamic Bus Scheduling and Load Balancing algo. It calculates the net load at each station, and determines the number of buses required for each station based on demand.


Problem Title: Dynamic Metro Bus Fleet Management

# Problem Description:
A metro bus system operates across 24 stations, each located 1 kilometer apart. The buses in the fleet have the following constraints and features:

Bus Capacity: Each bus can accommodate up to 160 passengers.
Base Interval: The default time interval between buses at a station is 5 minutes.
Automatic Data Collection: Each station has automated systems to record the inflow (number of passengers entering) and outflow (number of passengers exiting) in real-time.
Your task is to write a program that dynamically allocates buses across stations to minimize overcrowding and optimize service during high-demand periods. The system should account for:

Net Load Calculation: The net passenger load at each station is the difference between the inflow and outflow. This determines the number of passengers waiting at a station.
Future Demand Prediction: Assume a 10% increase in inflow for future passenger demand at each station.
Emergency Dispatch: If the inflow at any station exceeds 5 times the bus capacity, dispatch a dedicated emergency bus to that station immediately.
Interval Adjustment: Adjust the bus interval at a station dynamically:
If the predicted passenger load exceeds the current service capacity, reduce the interval to deploy more buses.
The interval should not drop below 1 minute.
# Input Format:

Integer n: The number of stations (1 ≤ n ≤ 24).
Integer busCapacity: The capacity of each bus (1 ≤ busCapacity ≤ 500).
Integer baseInterval: The base time interval between buses in minutes (1 ≤ baseInterval ≤ 15).
List of tuples stations: A list of n tuples, where each tuple contains three integers:
id (1 ≤ id ≤ 24): The station ID.
inflow (0 ≤ inflow ≤ 10,000): The number of passengers entering the station.
outflow (0 ≤ outflow ≤ 10,000): The number of passengers exiting the station.
