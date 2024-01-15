#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    int priority;
    Node<T>* next;
};

template <typename T>
class PriorityQueue {
private:
    Node<T>* front;

public:
    PriorityQueue();
    ~PriorityQueue();

    bool IsEmpty() const;
    void InsertWithPriority(const T& item, int priority);
    T PullHighestPriorityElement();
    T Peek() const;
    void Show() const;
};

#endif // PRIORITYQUEUE_H
