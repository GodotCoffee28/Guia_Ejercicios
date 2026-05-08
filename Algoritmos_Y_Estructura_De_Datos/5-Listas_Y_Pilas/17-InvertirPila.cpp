#include<iostream>


using namespace std;
//Una Stack es el primero que va de manera el primero que llega es el primero en salir
//First in First out FIFO Como una Stack de platos
//Ultimo entrar es el primero en salir Last input first output LIFO
template<typename T>
/*Utilizando únicamente las primitivas de la clase Pila, se quiere que Ud. 
desarrolle un procedimiento que dada una pila P, la invierta. No debe utilizar estructuras auxiliares.*/
class Stack{
    private:
    struct Node{
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n){} 
    };
    Node* topNode; //puntero al tope
    int count; //Contador de elementos
public:

    //Constructor
    Stack(): topNode(nullptr), count(0){}
        // **CONSTRUCTOR DE COPIA (DEEP COPY)**
    // Es crucial para evitar la doble liberación de memoria
    Stack(const Stack& other) : topNode(nullptr), count(0) {
        if (other.IsEmpty()) {
            return; // No hay nada que copiar si la otra pila está vacía
        }

        // Usamos una pila auxiliar para copiar los elementos en el orden correcto.
        // Primero, copiamos los elementos de 'other' a tempStack en orden inverso
        // (el tope de 'other' será la base de tempStack, y viceversa)
        Stack<T> tempStack;
        Node* current = other.topNode;
        while (current != nullptr) {
            tempStack.Push(current->data);
            current = current->next;
        }

        // Luego, "desapilamos" de tempStack y "apilamos" en 'this' pila.
        // Esto copiará los elementos en el orden correcto (de base a tope)
        while (!tempStack.IsEmpty()) {
            Push(tempStack.Pop());
        }
    }

    // **OPERADOR DE ASIGNACIÓN DE COPIA (DEEP COPY)**
    // También es crucial para evitar la doble liberación de memoria cuando haces pila1 = pila2;
    Stack& operator=(const Stack& other) {
        if (this != &other) { // Evita la auto-asignación (pila = pila;)
            Clear(); // Primero, limpia los elementos actuales de esta pila

            if (other.IsEmpty()) {
                return *this; // No hay nada que copiar si la otra pila está vacía
            }

            // Misma lógica de copia profunda que en el constructor de copia
            Stack<T> tempStack;
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
    //Destructor
    ~Stack(){
        Clear();
    }

    
    int Size()const {
        return count;
    }
    bool IsEmpty() const{
        return count==0;
    }
    
    void Clear(){
        while (!IsEmpty())
        {
            Pop();
        }
        
    }
    /*void Pop(){ //Pop eliminar
        if(IsEmpty()){
            throw std :: out_of_range("Error: Pop en Pila vacía"); 
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }*/
        T Pop(){ //Pop eliminar
        if(IsEmpty()){
            throw std :: out_of_range("Error: Pop en Pila vacía"); 
        }
        Node* temp = topNode;
        T data = topNode->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return data;
    }
    void Push(const T &d){ //Push agregar
        topNode = new Node(d, topNode);
        count++;
    }


    //acceso al primero en la pila
    T Top()const{
        if(IsEmpty()){
            throw std :: out_of_range("La Pila esta vacía"); 
        }
        return topNode->data;
    }
};
template<typename T>
void insertAux(Stack<T>& P, T Item){
        if(P.IsEmpty()){
            P.Push(Item);
            return;
        }
                        mostrarPila(P);
    T temp = P.Pop();
    insertAux(P, Item);
    P.Push(temp);
}
template<typename T>
void InvertirPila(Stack<T> &P){
    if(P.IsEmpty()) return;
    mostrarPila(P);
    T temp = P.Pop();
    InvertirPila(P);
    insertAux(P, temp);
}
template<typename T>
void mostrarPila(Stack<T> pila){
    if (pila.IsEmpty()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    std::cout << "Contenido de la pila (del tope a la base):" << std::endl;
    while (!pila.IsEmpty()) {
        std::cout << pila.Top() << std::endl;
        pila.Pop();
    }
}
int main(){
    Stack<int> MyStack;
    MyStack.Push(1);
    MyStack.Push(2);
    MyStack.Push(3);
    MyStack.Push(4);
    mostrarPila(MyStack);
    InvertirPila(MyStack);
    mostrarPila(MyStack);
}