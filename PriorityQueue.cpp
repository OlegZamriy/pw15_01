#include "PriorityQueue.h"

template <typename T>
PriorityQueue<T>::PriorityQueue() : front(nullptr) {}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    while (!IsEmpty()) {
        PullHighestPriorityElement();
    }
}

template <typename T>
bool PriorityQueue<T>::IsEmpty() const {
    return front == nullptr;
}

template <typename T>
void PriorityQueue<T>::InsertWithPriority(const T& item, int priority) {
    Node<T>* newNode = new Node<T>{ item, priority, nullptr };

    if (IsEmpty() || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    }
    else {
        Node<T>* current = front;
        while (current->next != nullptr && priority <= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
T PriorityQueue<T>::PullHighestPriorityElement() {
    if (IsEmpty()) {
        std::cerr << "PriorityQueue is empty. Cannot pull highest priority element.\n";
        return T();
    }

    Node<T>* temp = front;
    T item = temp->data;
    front = front->next;
    delete temp;

    return item;
}

template <typename T>
T PriorityQueue<T>::Peek() const {
    if (IsEmpty()) {
        std::cerr << "PriorityQueue is empty. Cannot peek.\n";
        return T();
    }

    return front->data;
}

template <typename T>
void PriorityQueue<T>::Show() const {
    if (IsEmpty()) {
        std::cout << "PriorityQueue is empty.\n";
        return;
    }

    Node<T>* current = front;
    while (current != nullptr) {
        std::cout << "Data: " << current->data << " Priority: " << current->priority << "\n";
        current = current->next;
    }
}

template class PriorityQueue<int>;
