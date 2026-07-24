#include <iostream>
#include "../9-Estructuras_Base/ListaArreglos.h"

using namespace std;

/*
 * Ejercicio 5: Implementar una función mezcla2 que tenga como parámetros dos listas con arreglos
 * de enteros ordenados de menor a mayor y que devuelva una nueva lista con arreglo con la unión
 * de ambas listas anteriores con sus elementos ordenados de la misma forma.
 * 
 * NOTA: La lógica de la lista de arreglos y sus métodos resolutivos se movieron
 * a structures base (ListaArreglos.h) por consistencia y reutilización.
 */

int main() {
    cout << "=== EJERCICIO 5: MEZCLA DE LISTAS DE ARREGLOS ORDENADOS ===" << endl << endl;

    ListaArreglos MisEnteros;
    ListaArreglos MisOtrosEnteros;

    int Arreglo1[] = {3, 2, 7, 8, 4};
    int Arreglo2[] = {6, 7, 8, 9, 10};
    int Arreglo3[] = {1, 2, 4, 11};

    int size1 = sizeof(Arreglo1) / sizeof(Arreglo1[0]);
    int size2 = sizeof(Arreglo2) / sizeof(Arreglo2[0]);
    int size3 = sizeof(Arreglo3) / sizeof(Arreglo3[0]);

    MisEnteros.insert(Arreglo1, MisEnteros.first(), size1);
    MisEnteros.insert(Arreglo2, MisEnteros.last(), size2);
    
    MisOtrosEnteros.insert(Arreglo3, MisOtrosEnteros.first(), size3);

    cout << "Lista 1 antes de ordenar: "; MisEnteros.printAll();
    cout << "Lista 2 antes de ordenar: "; MisOtrosEnteros.printAll();
    
    MisEnteros.OrderAscendentAll();
    MisOtrosEnteros.OrderAscendentAll();

    cout << "Lista 1 ordenada: "; MisEnteros.printAll();
    cout << "Lista 2 ordenada: "; MisOtrosEnteros.printAll();

    cout << "--- Mezclando Listas ---" << endl;
    
    // Invocamos el método miembro estático que realiza la mezcla
    ListaArreglos Mezclada = ListaArreglos::mezcla2(MisEnteros, MisOtrosEnteros);
    
    cout << "Resultado de la mezcla: "; Mezclada.printAll();
    cout << "---------------------------------------------" << endl;

    return 0;
}
