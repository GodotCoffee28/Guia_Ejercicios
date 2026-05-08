#ifndef DIPOLO_H
#define DIPOLO_H

#include <iostream>
#include <stdexcept>

/**
 * @brief Estructura de datos Dipolo (Deque / Double-Ended Queue)
 */
template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;
    Node* tail;
    int count;

public:
    Deque();
    Deque(const Deque& other);
    Deque& operator=(const Deque& other);
    ~Deque();

    int Size() const;
    bool IsEmpty() const;
    void Clear();

    void PushFront(const T& d);
    void PushBack(const T& d);
    T PopFront();
    T PopBack();
    
    T Front() const;
    T Back() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Deque<U>& dq);
};

// Implementación

template <typename T>
Deque<T>::Deque() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
Deque<T>::Deque(const Deque& other) : head(nullptr), tail(nullptr), count(0) {
    Node* current = other.head;
    while (current) {
        PushBack(current->data);
        current = current->next;
    }
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    if (this != &other) {
        Clear();
        Node* current = other.head;
        while (current) {
            PushBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Deque<T>::~Deque() {
    Clear();
}

template <typename T>
int Deque<T>::Size() const {
    return count;
}

template <typename T>
bool Deque<T>::IsEmpty() const {
    return count == 0;
}

template <typename T>
void Deque<T>::Clear() {
    while (!IsEmpty()) {
        PopFront();
    }
}

template <typename T>
void Deque<T>::PushFront(const T& d) {
    if (IsEmpty()) {
        head = tail = new Node(d);
    } else {
        head = new Node(d, head);
    }
    count++;
}

template <typename T>
void Deque<T>::PushBack(const T& d) {
    Node* newNode = new Node(d);
    if (IsEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <typename T>
T Deque<T>::PopFront() {
    if (IsEmpty()) throw std::out_of_range("Deque is empty");
    Node* temp = head;
    T data = temp->data;
    head = head->next;
    delete temp;
    count--;
    if (head == nullptr) tail = nullptr;
    return data;
}

template <typename T>
T Deque<T>::PopBack() {
    if (IsEmpty()) throw std::out_of_range("Deque is empty");
    T data;
    if (head == tail) {
        data = head->data;
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        data = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    count--;
    return data;
}

template <typename T>
T Deque<T>::Front() const {
    if (IsEmpty()) throw std::out_of_range("Deque is empty");
    return head->data;
}

template <typename T>
T Deque<T>::Back() const {
    if (IsEmpty()) throw std::out_of_range("Deque is empty");
    return tail->data;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Deque<U>& dq) {
    typename Deque<U>::Node* current = dq.head;
    os << "[";
    while (current) {
        os << current->data;
        if (current->next) os << ", ";
        current = current->next;
    }
    os << "]";
    return os;
}

#endif // DIPOLO_H
