#include <iostream>
#include "../9-Estructuras_Base/ListaSimple.h"

using namespace std;

/*
 * Ejercicio 12: Cree una función que elimine de una lista simplemente enlazada
 * de enteros, los valores repetidos.
 */

void eliminarRepetidos(intList& lista) {
    lista.eliminarRepetidos();
}

void imprimirFila(intList& lista) {
    intList::tPosition current = lista.First();
    if (current == lista.Last()) {
        cout << "[ Lista Vacia ]" << endl;
        return;
    }
    cout << "[ ";
    while (current != lista.Last()) {
        cout << lista.Get(current);
        lista.Next(current);
        if (current != lista.Last()) {
            cout << " -> ";
        }
    }
    cout << " ]" << endl;
}

int main() {
    cout << "=== EJERCICIO 12: ELIMINAR VALORES REPETIDOS ===" << endl << endl;

    // Caso 1: Lista vacía
    intList listaVacia;
    cout << "Caso 1: Lista vacia" << endl;
    cout << "Antes: "; imprimirFila(listaVacia);
    eliminarRepetidos(listaVacia);
    cout << "Despues: "; imprimirFila(listaVacia);
    cout << "---------------------------------------------" << endl;

    // Caso 2: Sin elementos repetidos
    intList listaSinRepetidos;
    intList::tPosition pos2 = listaSinRepetidos.First();
    listaSinRepetidos.Insert(1, pos2);
    listaSinRepetidos.Insert(2, pos2);
    listaSinRepetidos.Insert(3, pos2);
    listaSinRepetidos.Insert(4, pos2);
    cout << "Caso 2: Lista sin repetidos" << endl;
    cout << "Antes: "; imprimirFila(listaSinRepetidos);
    eliminarRepetidos(listaSinRepetidos);
    cout << "Despues: "; imprimirFila(listaSinRepetidos);
    cout << "---------------------------------------------" << endl;

    // Caso 3: Todos los elementos iguales
    intList listaTodosIguales;
    intList::tPosition pos3 = listaTodosIguales.First();
    listaTodosIguales.Insert(5, pos3);
    listaTodosIguales.Insert(5, pos3);
    listaTodosIguales.Insert(5, pos3);
    listaTodosIguales.Insert(5, pos3);
    cout << "Caso 3: Lista con todos los elementos iguales" << endl;
    cout << "Antes: "; imprimirFila(listaTodosIguales);
    eliminarRepetidos(listaTodosIguales);
    cout << "Despues: "; imprimirFila(listaTodosIguales);
    cout << "---------------------------------------------" << endl;

    // Caso 4: Repetidos al inicio, medio y final (y no contiguos)
    intList listaVariosRepetidos;
    intList::tPosition pos4 = listaVariosRepetidos.First();
    listaVariosRepetidos.Insert(10, pos4); // D1
    listaVariosRepetidos.Insert(20, pos4); // D2
    listaVariosRepetidos.Insert(10, pos4); // D3 (Duplicado)
    listaVariosRepetidos.Insert(30, pos4); // D4
    listaVariosRepetidos.Insert(20, pos4); // D5 (Duplicado)
    listaVariosRepetidos.Insert(10, pos4); // D6 (Duplicado)
    listaVariosRepetidos.Insert(40, pos4); // D7
    cout << "Caso 4: Lista con repetidos al inicio, medio y fin" << endl;
    cout << "Antes: "; imprimirFila(listaVariosRepetidos);
    eliminarRepetidos(listaVariosRepetidos);
    cout << "Despues: "; imprimirFila(listaVariosRepetidos);
    cout << "---------------------------------------------" << endl;

    return 0;
}
