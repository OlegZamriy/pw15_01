#include "Stop.h"
#include <iostream>

using namespace std;

Stop::Stop(double avgPassArrival, double avgBusArrival, bool isEnd, int capacity, double avgStay)
    : averagePassengerArrivalTime(avgPassArrival),
    averageBusArrivalTime(avgBusArrival),
    isEndStop(isEnd),
    maxCapacity(capacity),
    averageStayTime(avgStay),
    currentPassengerCount(0) {}

void Stop::simulate() {
    if (rand() % 100 < 50) {
        currentPassengerCount++;
        cout << "Passenger arrived at the stop. Current count: " << currentPassengerCount << endl;
    }

    if (rand() % 100 < 30) {
        if (currentPassengerCount > 0) {
            int passengersInBus = rand() % (currentPassengerCount + 1);
            currentPassengerCount -= passengersInBus;
            cout << "Bus arrived. Passengers in the bus: " << passengersInBus
                << ". Current count at the stop: " << currentPassengerCount << endl;
        }
        else {
            cout << "Bus arrived, but no passengers." << endl;
        }
    }

    if (currentPassengerCount > 0) {
        double stayTime = rand() % 10 + 1;
        cout << "Passengers are waiting for " << stayTime << " min. at the stop." << endl;
    }
}
