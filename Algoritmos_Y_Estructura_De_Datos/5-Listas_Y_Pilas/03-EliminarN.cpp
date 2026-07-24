#include <iostream>
#include "../9-Estructuras_Base/ListaArreglos.h"

using namespace std;

/*
 * Ejercicio 3: Dada una lista con arreglos de enteros y un número entero n,
 * implementar una función donde se eliminen todos los números n de la lista.
 * 
 * NOTA: La lógica de la lista de arreglos y sus métodos resolutivos se movieron
 * a structures base (ListaArreglos.h) por consistencia y reutilización.
 */

int main() {
    cout << "=== EJERCICIO 3: ELIMINAR N DE LISTA DE ARREGLOS ===" << endl << endl;

    ListaArreglos MisEnteros;
    cout << "LA LISTA ESTA VACIA? " << (MisEnteros.IsEmpty() ? "Si" : "No") << endl;
    MisEnteros.printAll();
    
    int Arreglo1[] = {3, 2, 7, 8, 4};
    int Arreglo2[] = {6, 7, 8, 9, 7, 7, 69, 10, 3};
    int Arreglo3[] = {11, 1, 13, 14, 9, 2, 4, 19, 17, 18};
    
    int size1 = sizeof(Arreglo1) / sizeof(Arreglo1[0]);
    int size2 = sizeof(Arreglo2) / sizeof(Arreglo2[0]);
    int size3 = sizeof(Arreglo3) / sizeof(Arreglo3[0]);

    MisEnteros.insert(Arreglo1, MisEnteros.first(), size1);
    MisEnteros.insert(Arreglo2, MisEnteros.last(), size2);
    MisEnteros.insert(Arreglo3, MisEnteros.last(), size3);
    
    cout << "TODOS LOS NODOS ANTES DE ELIMINAR: " << endl;
    MisEnteros.printAll();
    cout << endl;

    int n = 7;
    cout << "--- Buscando y eliminando el numero " << n << " ---" << endl;
    
    // Invocamos el método miembro que realiza la eliminación de n
    MisEnteros.deleteByValue(MisEnteros.find(n), n);
    
    cout << "TODOS LOS NODOS DESPUES DE ELIMINAR: " << endl;
    MisEnteros.printAll();
    cout << "---------------------------------------------" << endl;

    return 0; 
}