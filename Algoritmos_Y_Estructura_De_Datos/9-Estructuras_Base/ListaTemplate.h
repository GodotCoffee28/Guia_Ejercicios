#ifndef LISTATEMPLATE_H
#define LISTATEMPLATE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n){}
    };
    Node* head;
    Node* tail;
    int size;

public:
    typedef Node* tPosition;

    List() : size(0) {
        tail = new Node(T());
        head = new Node(T(), tail);
        size = 0;
    }

    ~List() {
        clear();
        delete head;
        delete tail;
    }

    bool IsEmpty() {
        return size == 0;
    }

    tPosition first() {
        return (head->next != tail) ? head->next : tail;
    }

    tPosition last() {
        return tail;
    }

    void next(tPosition& pValue) {
        if (pValue != tail) {
            pValue = pValue->next;
        }
    }

    T& get(tPosition v) {
        return v->data;
    }

    void insert(const T& d, tPosition v) {
        tPosition current = head;
        while (current->next != v) {
            current = current->next;
        }
        current->next = new Node(d, v);
        size++;
    }

    void Delete(tPosition v) {
        if (v == tail || IsEmpty()) {
            return;
        }
        tPosition current = head;
        while (current->next != v) {
            current = current->next;
        }
        current->next = v->next;
        delete v;
        size--;
    }

    void printFirst() {
        tPosition current = first();
        cout << get(current) << endl;
    }

    void printAll() {
        tPosition current = first();
        while (current != tail) {
            cout << get(current) << " ";
            next(current);
        }
        cout << endl;
    }

    void clear() {
        tPosition current = head->next;
        while (current != tail) {
            tPosition temp = current;
            current = current->next;
            delete temp;
        }
        head->next = tail;
        size = 0;
    }

    void swap(tPosition a, tPosition b) {
        if (a == nullptr || a == tail || b == nullptr || b == tail) {
            cout << "Error, swaping de posiciones nulas o no validad." << endl;
            return;
        }
        T aux = a->data;
        a->data = b->data;
        b->data = aux;
    }

    // Funciones adicionales genéricas para consistencia
    tPosition find(const T& d) {
        tPosition current = first();
        while (current != tail) {
            if (get(current) == d) {
                return current;
            }
            next(current);
        }
        return tail;
    }

    void deleteByValue(const T& d) {
        tPosition pos = find(d);
        if (pos != tail) {
            Delete(pos);
        }
    }

    void sort() {
        if (IsEmpty() || size <= 1) return;
        bool swapped = true;
        while (swapped) {
            swapped = false;
            tPosition current = first();
            while (current->next != tail) {
                tPosition nextNode = current->next;
                if (get(current) > get(nextNode)) {
                    swap(current, nextNode);
                    swapped = true;
                }
                current = current->next;
            }
        }
    }
};

#endif // LISTATEMPLATE_H
