#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    T* elements;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int capacity);
    ~Queue();

    bool IsEmpty() const;
    bool IsFull() const;

    void Enqueue(const T& item);
    T Dequeue();

    void Show() const;
};

#endif // QUEUE_H
