#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include<iostream>
using namespace std;



class intList{

    struct Node{
        int value;  
        Node* next; //NO es recursivo, es un dato que se usa a si mismo
        //Node* back esto sirve para hacer la lista doblemente enlazada

        Node(int _value, Node* _next = nullptr) : value(_value), next(_next){}
        //Originalmente los struct no tenian constructores, para evitar Node.data
        /*
        Es equivalente a esto
        Node(int _value, Node* _next = nullptr){
            value = _value;
            next = _next;
        }
        */
    };
    Node* head; //Nodo cabeza o inicio
    Node* tail; // Nodo cola o final
    int size; //cantidad de elementos de la lista

    public:

    typedef Node* tPosition;
    

    intList() : size(0){ //Casos bases de la lista
        tail = new Node(0);
        head = new Node(0, tail); //Paso tail pq si soy el unico elemento soy el primero y el final a la vez
        //Que la lista este vacía, que la lista tenga 1 elemento, y que la lista tenga N elementos
    }
    ~intList(){
        Clear();       
    }

    //Primitivas
    //1-.Verificar si esta vacía
    bool IsEmpty(){
        return size == 0; //Si el tamaño es 0, la lista esta vacía, True
    }
    //2-. Obtener el primer nodo de la lista
    //Es totalmente equivalente a Node*, es simplemente un alias
    tPosition First(){
        return (head -> next != tail) ? head->next: tail; 
        //Si el siguiente elemento a mi, es distinto de la cola, es porque hay otro elemento
        //Tambien != nullptr funcionaría
    }
    //3-. Obtener el ultimo nodo de la lista
    tPosition Last(){
        return tail;
    }

    //4-. Avanzar al siguiente nodo
    void Next(tPosition& pValue){
        if(pValue != tail){
            pValue = pValue->next;
        }
    }
    //5-. Obtener dato o valor de nodo
    int& Get(tPosition pValue){
        return pValue->value;
    }

    //6-. Insertar elemento antes del nodo v
    void Insert(int d, tPosition v){
        tPosition current = head;
        while(current->next != v){
            current = current->next; //Iteramos hasta que el siguiente de current sea v
        }
        current->next = new Node(d, v);  //hacemos un nuevo nodo y este tendra el dato pasado, y el next sera v
        size++;
    }

    //7-. Eliminar
    void Delete(tPosition v){
        if (v == tail){
            delete v;
            size--;
            return;
        }
        tPosition current = head;
        while(current->next != v){
            Next(current);
        }
        current->next = v->next; //Antes de borrar el nodo, le asigno el siguiente del nodo a borrar
        //a el next de mi nodo actual, no se borran los punteros, se reasignan punteros
        delete v;
        size--;
    }
    //8-. Mostrar todo
    void PrintAll(){
        tPosition current = First(); //Podria ser head
        while(current !=  tail){
            cout<<Get(current)<<endl;
            Next(current);
        }
    }
    //9-.
    void Clear(){
        tPosition current = head;
        while(current->next != tail){
            tPosition aux = current;
            Next(current);
            delete aux;
        }
        delete current;
        delete tail;
        size = 0;
    }

    // Métodos para el Ejercicio 15: Invertir lista sin crear una nueva ni mover elementos físicamente.
    private:
    Node* reverse_rec(Node* curr) {
        if (curr == tail || curr->next == tail) {
            return curr;
        }
        Node* new_head = reverse_rec(curr->next);
        curr->next->next = curr;
        curr->next = tail;
        return new_head;
    }

    public:
    void reverseIterative() {
        if (head->next == tail) return; // Lista vacía
        Node* prev = tail;
        Node* curr = head->next;
        while (curr != tail) {
            Node* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        head->next = prev;
    }

    void reverseRecursive() {
        if (head->next == tail) return; // Lista vacía
        head->next = reverse_rec(head->next);
    }

    // Métodos para los Ejercicios 9 y 12
    int suma() {
        int total = 0;
        Node* current = head->next;
        while (current != tail) {
            total += current->value;
            current = current->next;
        }
        return total;
    }

    void eliminarRepetidos() {
        Node* current = head->next;
        while (current != tail) {
            int valorBuscar = current->value;
            Node* runner = current->next;
            while (runner != tail) {
                if (runner->value == valorBuscar) {
                    Node* temp = runner;
                    runner = runner->next;
                    Delete(temp);
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
};

#endif // LISTASIMPLE_H
