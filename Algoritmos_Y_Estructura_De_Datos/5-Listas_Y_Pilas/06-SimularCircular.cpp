#include <iostream>
#include "../9-Estructuras_Base/ListaCircular.h"

using namespace std;

/*
 * Ejercicio 6: Implemente una lista con arreglo que simule una lista
 * circular de caracteres con n posiciones y dados dos enteros m e i,
 * imprima m valores a partir de la posición i.
 */

int main() {
    cout << "=== EJERCICIO 6: SIMULAR LISTA CIRCULAR ===" << endl << endl;

    ListaCircular MyList;
    MyList.insert("Hoola");
    MyList.insert("que onda");
    MyList.insert("porque");
    MyList.insert("si");
    
    cout << "Lista circular (mostrando 4 valores a partir de posicion 2):" << endl;
    MyList.printFromPosition(4, 2);
    cout << "---------------------------------------------" << endl;

    return 0;
}