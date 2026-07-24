#include <iostream>
#include "../9-Estructuras_Base/PilaSimple.h"

using namespace std;

/*
 * Ejercicio 17: Utilizando únicamente las primitivas de la clase Pila, se quiere que Ud.
 * desarrolle un procedimiento que dada una pila P, la invierta. No debe utilizar estructuras auxiliares.
 * 
 * NOTA: La lógica de la inversión está implementada dentro de la estructura base (PilaSimple.h)
 * mediante el método público PilaSimple::invertir() para mayor modularidad y reutilización.
 */

void InvertirPila(PilaSimple& P) {
    P.invertir();
}

void mostrarPila(PilaSimple pila) {
    if (pila.IsEmpty()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Contenido de la pila (del tope a la base):" << endl;
    pila.PrintAll();
}

int main() {
    cout << "=== EJERCICIO 17: INVERTIR PILA ===" << endl << endl;

    PilaSimple MyStack;
    MyStack.Push(1);
    MyStack.Push(2);
    MyStack.Push(3);
    MyStack.Push(4);

    cout << "--- Pila Antes de Invertir ---" << endl;
    mostrarPila(MyStack);
    cout << endl;

    InvertirPila(MyStack);

    cout << "--- Pila Despues de Invertir ---" << endl;
    mostrarPila(MyStack);
    cout << "---------------------------------------------" << endl;

    return 0;
}