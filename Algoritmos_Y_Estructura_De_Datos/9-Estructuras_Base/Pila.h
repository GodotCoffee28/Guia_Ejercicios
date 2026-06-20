#ifndef PILA_H
#define PILA_H

#include <stdexcept>

/**
 * @brief Estructura de datos Pila (Stack) - LIFO (Last In, First Out)
 */
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* topNode;
    int count;

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    int Size() const;
    bool IsEmpty() const;
    void Clear();
    void Push(const T& d);
    T Pop(); // Retorna el elemento y lo elimina
    T Top() const;
};

// Implementación de Templates (debe estar en el .h o incluida por él)

template <typename T>
Stack<T>::Stack() : topNode(nullptr), count(0) {}

template <typename T>
Stack<T>::Stack(const Stack& other) : topNode(nullptr), count(0) {
    if (other.IsEmpty()) return;
    
    // Para mantener el orden, usamos recursión o una estructura temporal
    Node* current = other.topNode;
    Stack<T> temp;
    while (current) {
        temp.Push(current->data);
        current = current->next;
    }
    while (!temp.IsEmpty()) {
        Push(temp.Pop());
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        Clear();
        if (!other.IsEmpty()) {
            Node* current = other.topNode;
            Stack<T> temp;
            while (current) {
                temp.Push(current->data);
                current = current->next;
            }
            while (!temp.IsEmpty()) {
                Push(temp.Pop());
            }
        }
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    Clear();
}

template <typename T>
int Stack<T>::Size() const {
    return count;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return count == 0;
}

template <typename T>
void Stack<T>::Clear() {
    while (!IsEmpty()) {
        Pop();
    }
}

template <typename T>
void Stack<T>::Push(const T& d) {
    topNode = new Node(d, topNode);
    count++;
}

template <typename T>
T Stack<T>::Pop() {
    if (IsEmpty()) throw std::out_of_range("Stack is empty");
    Node* temp = topNode;
    T data = temp->data;
    topNode = topNode->next;
    delete temp;
    count--;
    return data;
}

template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty()) throw std::out_of_range("Stack is empty");
    return topNode->data;
}

#endif // PILA_H
