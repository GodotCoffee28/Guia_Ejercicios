#ifndef COLA_H
#define COLA_H

#include <stdexcept>

/**
 * @brief Estructura de datos Cola (Queue) - FIFO (First In, First Out)
 */
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* front;
    Node* rear;
    int count;

public:
    Queue();
    ~Queue();

    int Size() const;
    bool IsEmpty() const;
    void Clear();
    void Enqueue(const T& d);
    T Dequeue(); // Retorna el elemento y lo elimina
    T Head() const;
};

// Implementación

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    Clear();
}

template <typename T>
int Queue<T>::Size() const {
    return count;
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return count == 0;
}

template <typename T>
void Queue<T>::Clear() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

template <typename T>
void Queue<T>::Enqueue(const T& d) {
    Node* newNode = new Node(d);
    if (IsEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

template <typename T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");
    Node* temp = front;
    T data = temp->data;
    front = front->next;
    delete temp;
    count--;
    if (front == nullptr) {
        rear = nullptr;
    }
    return data;
}

template <typename T>
T Queue<T>::Head() const {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");
    return front->data;
}

#endif // COLA_H
