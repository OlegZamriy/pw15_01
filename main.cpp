#include "Queue.h"

int main() {
    Queue<int> intQueue(5);

    intQueue.Enqueue(1);
    intQueue.Enqueue(2);
    intQueue.Enqueue(3);
    intQueue.Show(); 

    intQueue.Dequeue();
    intQueue.Show();

    intQueue.Enqueue(4);
    intQueue.Enqueue(5);
    intQueue.Enqueue(6); 

    return 0;
}
