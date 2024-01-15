#pragma once

#include <queue>
#include <string>
#include <ctime>

struct PrintRequest {
    std::string user;
    int priority;
    time_t requestTime;

    PrintRequest(const std::string& u, int p);
};

class PrinterQueue {
private:
    std::queue<PrintRequest> printQueue;
    std::queue<std::pair<std::string, time_t>> printHistory;

public:
    void addPrintRequest(const std::string& user, int priority);
    void processPrintRequests();
    void printStatistics() const;
};
