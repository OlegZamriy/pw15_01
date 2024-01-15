#include "PrinterQueue.h"
#include <iostream>

PrintRequest::PrintRequest(const std::string& u, int p)
    : user(u), priority(p), requestTime(time(nullptr)) {}

void PrinterQueue::addPrintRequest(const std::string& user, int priority) {
    printQueue.push(PrintRequest(user, priority));
}

void PrinterQueue::processPrintRequests() {
    while (!printQueue.empty()) {
        PrintRequest currentRequest = printQueue.front();
        printQueue.pop();

        std::cout << "Printing for user: " << currentRequest.user << " (Priority: " << currentRequest.priority << ")\n";

        printHistory.push(std::make_pair(currentRequest.user, currentRequest.requestTime));
    }
}

void PrinterQueue::printStatistics() const {
    std::cout << "Printing Statistics:\n";

    std::queue<std::pair<std::string, time_t>> tempPrintHistory = printHistory;

    while (!tempPrintHistory.empty()) {
        std::pair<std::string, time_t> historyEntry = tempPrintHistory.front();
        tempPrintHistory.pop();

        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &historyEntry.second);
        std::cout << "User: " << historyEntry.first << ", Print Time: " << buffer;
    }
}

