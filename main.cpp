#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.InsertWithPriority(5, 2);
    priorityQueue.InsertWithPriority(10, 1);
    priorityQueue.InsertWithPriority(3, 3);
    priorityQueue.Show(); 

    int highestPriority = priorityQueue.PullHighestPriorityElement();
    std::cout << "Pulled highest priority element: " << highestPriority << "\n"; 

    int peekedElement = priorityQueue.Peek();
    std::cout << "Peeked element: " << peekedElement << "\n"; 

    priorityQueue.Show(); 

    return 0;
}
