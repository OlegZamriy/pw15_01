#include "PrinterQueue.h"

int main() {
    PrinterQueue printer;

    printer.addPrintRequest("User1", 2);
    printer.addPrintRequest("User2", 1);
    printer.addPrintRequest("User3", 3);

    printer.processPrintRequests();

    printer.printStatistics();

    return 0;
}
