#ifndef PILASIMPLE_H
#define PILASIMPLE_H

#include <iostream>
#include <stdexcept>

using namespace std;

class PilaSimple {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* topNode;
    int count;

    // Método auxiliar recursivo para el Ejercicio 17: Invertir Pila
    void insertAtBottom(int item) {
        if (IsEmpty()) {
            Push(item);
            return;
        }
        int temp = Pop();
        insertAtBottom(item);
        Push(temp);
    }

public:
    PilaSimple() : topNode(nullptr), count(0) {}

    // Constructor de copia
    PilaSimple(const PilaSimple& other) : topNode(nullptr), count(0) {
        if (other.IsEmpty()) {
            return;
        }
        // Usar pila auxiliar para copiar en orden correcto
        PilaSimple tempStack;
        Node* current = other.topNode;
        while (current != nullptr) {
            tempStack.Push(current->data);
            current = current->next;
        }
        while (!tempStack.IsEmpty()) {
            Push(tempStack.Pop());
        }
    }

    // Operador de asignación
    PilaSimple& operator=(const PilaSimple& other) {
        if (this != &other) {
            Clear();
            if (other.IsEmpty()) {
                return *this;
            }
            PilaSimple tempStack;
            Node* current = other.topNode;
            while (current != nullptr) {
                tempStack.Push(current->data);
                current = current->next;
            }
            while (!tempStack.IsEmpty()) {
                Push(tempStack.Pop());
            }
        }
        return *this;
    }

    ~PilaSimple() {
        Clear();
    }

    bool IsEmpty() const {
        return count == 0;
    }

    int Size() const {
        return count;
    }

    void Push(int val) {
        topNode = new Node(val, topNode);
        count++;
    }

    int Pop() {
        if (IsEmpty()) {
            throw out_of_range("Error: Pop en Pila vacia");
        }
        Node* temp = topNode;
        int val = temp->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return val;
    }

    int Top() const {
        if (IsEmpty()) {
            throw out_of_range("Error: Top en Pila vacia");
        }
        return topNode->data;
    }

    void Clear() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    void PrintAll() const {
        if (IsEmpty()) {
            cout << "[ Pila Vacia ]" << endl;
            return;
        }
        Node* current = topNode;
        cout << "[TOPE] -> ";
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) {
                cout << " -> ";
            }
        }
        cout << " -> [BASE]" << endl;
    }

    // Método para el Ejercicio 17: Invertir Pila
    void invertir() {
        if (IsEmpty()) return;
        int temp = Pop();
        invertir();
        insertAtBottom(temp);
    }
};

#endif // PILASIMPLE_H
