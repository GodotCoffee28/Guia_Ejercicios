#include "../9-Estructuras_Base/ListaSimple.h"
#include <iostream>

using namespace std;

/*
 * Ejercicio 9: Realice una función ‘suma’ que retorne la suma de todos los
 * elementos de una lista dada por parámetro.
 */

/*    int total = 0;
   intList::tPosition current = lista.First();
   while (current != lista.Last()) {
       total += lista.Get(current);
       lista.Next(current);
   }
   return total;
   */
int suma(intList &lista) { return lista.suma(); }

int main() {
  cout << "=== EJERCICIO 9: SUMA DE ELEMENTOS DE UNA LISTA ===" << endl << endl;

  // Caso 1: Lista vacía
  intList listaVacia;
  cout << "Caso 1: Lista vacia" << endl;
  cout << "Contenido de la lista: ";
  listaVacia.PrintAll();
  cout << "Suma de elementos: " << suma(listaVacia) << " (Esperado: 0)" << endl;
  cout << "---------------------------------------------" << endl;

  // Caso 2: Lista con un elemento
  intList listaUnElemento;
  listaUnElemento.Insert(42, listaUnElemento.First());
  cout << "Caso 2: Lista con un elemento" << endl;
  cout << "Contenido de la lista: ";
  listaUnElemento.PrintAll();
  cout << "Suma de elementos: " << suma(listaUnElemento) << " (Esperado: 42)"
       << endl;
  cout << "---------------------------------------------" << endl;

  // Caso 3: Lista con múltiples elementos positivos y negativos
  intList listaVarios;
  intList::tPosition pos = listaVarios.First();
  listaVarios.Insert(10, pos);
  listaVarios.Insert(-5, pos);
  listaVarios.Insert(25, pos);
  listaVarios.Insert(3, pos);
  listaVarios.Insert(-8, pos);

  cout << "Caso 3: Lista con multiples elementos" << endl;
  cout << "Contenido de la lista:" << endl;
  listaVarios.PrintAll();
  cout << "Suma de elementos: " << suma(listaVarios) << " (Esperado: 25)"
       << endl;
  cout << "---------------------------------------------" << endl;

  return 0;
}
