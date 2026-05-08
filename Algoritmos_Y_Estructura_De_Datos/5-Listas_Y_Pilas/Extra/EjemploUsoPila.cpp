#include <iostream>
#include "../../9-Estructuras_Base/Pila.h" // Subir un nivel y entrar a Estructuras_Base

using namespace std;

int main() {
    Stack<int> miPila;

    miPila.Push(10);
    miPila.Push(20);
    miPila.Push(30);

    cout << "Tope de la pila: " << miPila.Top() << endl; // Deberia ser 30
    
    cout << "Desapilando: " << miPila.Pop() << endl;
    cout << "Nuevo tope: " << miPila.Top() << endl;

    return 0;
}
