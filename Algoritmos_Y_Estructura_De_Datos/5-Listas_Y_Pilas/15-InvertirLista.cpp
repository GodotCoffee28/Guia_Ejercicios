#include <iostream>
#include "../9-Estructuras_Base/ListaSimple.h"

using namespace std;

/*
 * Ejercicio 15: Elabore dos algoritmos (uno recursivo y otro iterativo) en el
 * cual dada una lista lineal en forma enlazada la invierta, sin crear una nueva
 * lista, ni mover los elementos físicamente de la lista.
 * 
 * NOTA: Los algoritmos iterativo y recursivo están implementados como métodos
 * miembro en la estructura base (ListaSimple.h) para poder modificar los enlaces
 * internos (Node::next) sin violar el encapsulamiento.
 */

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
    cout << "=== EJERCICIO 15: INVERTIR LISTA (ITERATIVO Y RECURSIVO) ===" << endl << endl;

    // Caso 1: Lista vacía
    cout << "Caso 1: Lista vacia" << endl;
    intList listaVacia;
    cout << "Original: "; imprimirFila(listaVacia);
    
    listaVacia.reverseIterative();
    cout << "Tras Inversion Iterativa: "; imprimirFila(listaVacia);
    
    listaVacia.reverseRecursive();
    cout << "Tras Inversion Recursiva: "; imprimirFila(listaVacia);
    cout << "---------------------------------------------" << endl;

    // Caso 2: Lista con un elemento
    cout << "Caso 2: Lista con un elemento" << endl;
    intList listaUnElemento;
    listaUnElemento.Insert(100, listaUnElemento.First());
    cout << "Original: "; imprimirFila(listaUnElemento);
    
    listaUnElemento.reverseIterative();
    cout << "Tras Inversion Iterativa: "; imprimirFila(listaUnElemento);
    
    listaUnElemento.reverseRecursive();
    cout << "Tras Inversion Recursiva: "; imprimirFila(listaUnElemento);
    cout << "---------------------------------------------" << endl;

    // Caso 3: Lista con múltiples elementos
    cout << "Caso 3: Lista con multiples elementos" << endl;
    intList listaVarios;
    intList::tPosition pos = listaVarios.First();
    listaVarios.Insert(50, pos);
    listaVarios.Insert(40, pos);
    listaVarios.Insert(30, pos);
    listaVarios.Insert(20, pos);
    listaVarios.Insert(10, pos);
    
    cout << "Original: "; imprimirFila(listaVarios);
    
    // Invertir de forma Iterativa
    listaVarios.reverseIterative();
    cout << "Tras Inversion Iterativa (esperado: 50 -> 40 -> 30 -> 20 -> 10):" << endl;
    cout << "Resultado: "; imprimirFila(listaVarios);
    
    // Invertir de forma Recursiva (debería volver a su orden original)
    listaVarios.reverseRecursive();
    cout << "Tras Inversion Recursiva (deberia volver al orden original: 10 -> 20 -> 30 -> 40 -> 50):" << endl;
    cout << "Resultado: "; imprimirFila(listaVarios);
    cout << "---------------------------------------------" << endl;

    return 0;
}
