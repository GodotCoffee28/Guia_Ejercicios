#include <iostream>
#include "../9-Estructuras_Base/PilaSimple.h"

using namespace std;

/*
 * Ejercicio 22: Dada una pila, se desea conocer el promedio de los elementos
 * que ella almacena. Como restricción la pila puede ser recorrida una sola vez.
 */

float Prom(PilaSimple p) {
    if (p.IsEmpty()) return 0.0f;
    
    int sum = 0;
    int size = p.Size();
    
    while (!p.IsEmpty()) {
        sum += p.Pop();
    }

    return (float)sum / size;
}

void printstack(PilaSimple p) {
    p.PrintAll();
}

int main() {
    cout << "=== EJERCICIO 22: PROMEDIO DE UNA PILA ===" << endl << endl;

    PilaSimple p;
    for (int i = 1; i <= 10; i++) {
        p.Push(i);
    }
    
    cout << "Pila actual:" << endl;
    printstack(p);
    cout << endl;
    
    cout << "El promedio de los valores de la pila es: " << Prom(p) << " (Esperado: 5.5)" << endl;
    cout << "---------------------------------------------" << endl;

    return 0;
}