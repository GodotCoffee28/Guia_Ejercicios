#include<iostream>
using namespace std;

template<typename T>
class List{

private:

    struct Node{
        T data; //Dato actual
        Node* next; //Direccion del siguiente dato
        Node(const T& d, Node* n = nullptr) : data(d), next(n){}
    };
    Node* head; //Nodo cabeza o principio
    Node* tail; //Nodo cola o final
    int size;
public :
        typedef Node* tPosition; //Asociarlo a un tipo de dato o alias
    List() : size(0){ //Se inicializa la lista o se empieza la lista
        tail = new Node(T()); //Direccion de ultimo elemento
        head = new Node(T(), tail); //Direccion del primer elemento, tail es un apuntador de head en el caso de inicio
        size = 0;
    }
    ~List(){
        delete head;
        delete tail;
    }
    //Verificar si la lista esta vacia
    bool IsEmpty(){
        return size==0;
    }
    //regresa el primero de la lista
    tPosition first(){//primitiva
        return (head->next != tail) ? head->next:tail; 
    } //Si el siguiente elemento es nulo o distinto de la cola es porque hay otro elemento y no es el primero y si no ocurre eso es porque es el primero


    //regresa el ultimo/ la cola
    tPosition last(){ //primitiva
        return tail;
    }
    //Avanzar al siguiente elemento
    void next(tPosition & pValue){ //primitiva
        if(pValue != tail){
            pValue = pValue->next;
        } //nos vamos moviendo mientras tengo un next
    }
    //Obtener el dato actual
    T &get(tPosition v){
        return v->data;
    }
    //Insertar un nuevo elemento
void insert(const T &d, tPosition v){
    tPosition current = head; //
    while(current->next != v){ //
        current = current->next; //
    }
    current->next = new Node(d, v); //
    size++; //
}

    void Delete(tPosition v){
        if(v==tail || IsEmpty()){
            delete v;
            size--;
            return;    
        }
        tPosition current=head;
        while( current->next != v){
            current = current->next;
        }//lo que hace es que cuando consigue el elmento que quiero eliminar reasigno el que esta despues de ese elemento
        //y elimino el elemento
        current->next = v->next;
        delete v;
        size--;
    }
    void printFirst(){
        tPosition current = first();
        cout<<get(current)<<endl;
    }
    void printAll(){
        tPosition current = first();
        while(current != tail){ // tenemos el primero y mientras sea diferente de la cola imprimimos
            cout << get(current)<<" ";
            next(current);
        }
        cout<<endl;
    }
void clear(){
    tPosition current = head->next; // Empezamos desde el primer nodo de datos.
    while (current != tail){        // Iteramos mientras 'current' no sea el nodo centinela 'tail'.
        tPosition temp = current;   // 1. Guardamos la dirección del nodo actual en 'temp'.
        current = current->next;    // 2. Avanzamos 'current' al siguiente nodo ANTES de borrar 'temp'.
        delete temp;              // 3. Ahora borramos el nodo guardado en 'temp'.
    }
    // Después de borrar todos los nodos de datos, la lista debe estar vacía.
    // Esto significa que head debe apuntar directamente a tail.
    head->next = tail; //
    size = 0;          //
}
void swap(tPosition a, tPosition b){
    if (a == nullptr || a == tail || b == nullptr || b == tail) {
        cout<<"Error, swaping de posiciones nulas o no validad."<<endl;
            // Manejar error o simplemente no hacer nada si las posiciones no son válidas para datos
            return;
        }
    T aux = a->data;
    a->data = b->data;
    b->data = aux;

}
};



int main(){

    List<int> myList;
    List<int> :: tPosition pos = myList.first();
    List<int> :: tPosition pos1 = myList.last();
    myList.insert(5, pos);
    myList.insert(10, pos);
    myList.insert(15, pos);
    cout<<"--Lista antes del swap--"<<endl;
    myList.printAll();
    cout<<"--Lista despues del swap"<<endl;
    myList.next(pos);


    myList.swap(pos, pos1);
    myList.printAll();

    myList.clear();

    myList.insert(5, pos);
    myList.insert(102, pos);
    myList.insert(153, pos);

    /*for(auto &i = myList.first(); i != myList.last(); myList.next(i)){
        cout<< myList.get(i)<<" ";
    }*/



    return 0;
}