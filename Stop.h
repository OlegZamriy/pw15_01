#ifndef STOP_H
#define STOP_H

class Stop {
public:
    Stop(double avgPassArrival, double avgBusArrival, bool isEnd, int capacity, double avgStay);

    void simulate();

private:
    double averagePassengerArrivalTime;
    double averageBusArrivalTime;
    bool isEndStop;
    int maxCapacity;
    double averageStayTime;
    int currentPassengerCount;
};

#endif
