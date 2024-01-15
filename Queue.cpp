#include "Queue.h"
#include <iostream>

template <typename T>
Queue<T>::Queue(int capacity) : capacity(capacity), front(0), rear(-1), size(0) {
    elements = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] elements;
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
bool Queue<T>::IsFull() const {
    return size == capacity;
}

template <typename T>
void Queue<T>::Enqueue(const T& item) {
    if (IsFull()) {
        std::cerr << "Queue is full. Cannot enqueue.\n";
        return;
    }

    rear = (rear + 1) % capacity;
    elements[rear] = item;
    size++;
}

template <typename T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) {
        std::cerr << "Queue is empty. Cannot dequeue.\n";
        return T();
    }

    T item = elements[front];
    front = (front + 1) % capacity;
    size--;
    return item;
}

template <typename T>
void Queue<T>::Show() const {
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    int index = front;
    for (int i = 0; i < size; ++i) {
        std::cout << elements[index] << " ";
        index = (index + 1) % capacity;
    }
    std::cout << "\n";
}

template class Queue<int>;
