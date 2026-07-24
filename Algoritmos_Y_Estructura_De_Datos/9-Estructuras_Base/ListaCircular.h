#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <iostream>
#include <string>

using namespace std;

class ListaCircular {
private:
    struct Node {
        string data;
        Node* next;
        Node(string d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
    int size;

public:
    typedef Node* tPosition;

    ListaCircular() : size(0) {
        head = new Node("");
        head->next = head;
    }

    ~ListaCircular() {
        clear();
        delete head;
    }

    int Size() const {
        return size;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    tPosition first() const {
        if (IsEmpty()) return head;
        return head->next;
    }

    tPosition headCentinela() const {
        return head;
    }

    void next(tPosition& node) const {
        node = node->next;
    }

    string& get(tPosition node) {
        return node->data;
    }

    void insert(const string& data) {
        if (IsEmpty()) {
            head->next = new Node(data, head);
        } else {
            tPosition current = first();
            while (current->next != head) {
                next(current);
            }
            tPosition newNode = new Node(data, head);
            current->next = newNode;
        }
        size++;
    }

    void clear() {
        if (IsEmpty()) return;
        tPosition current = head->next;
        while (current != head) {
            tPosition temp = current;
            current = current->next;
            delete temp;
        }
        head->next = head;
        size = 0;
    }

    void printNode(tPosition node) const {
        cout << node->data << " ";
    }

    void printFromPosition(int mValues, int iPosition) {
        if (IsEmpty() || mValues <= 0) return;

        tPosition current = first();
        int startPosition = iPosition % size;

        for (int count = 0; count < startPosition; ++count) {
            next(current);
        }
        for (int count = 0; count < mValues; ++count) {
            if (current == head) {
                next(current); // Nos saltamos el nodo centinela
            }
            printNode(current);
            next(current);
        }
        cout << endl;
    }
};

#endif // LISTACIRCULAR_H
