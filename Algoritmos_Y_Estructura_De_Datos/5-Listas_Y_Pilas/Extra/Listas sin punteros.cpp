#include <iostream>

const int MAX_NODOS = 100;
const int NULL_INDEX = -1;

// Este es el registro que vivirá dentro del arreglo
struct Nodo {
    int dato;
    int siguiente; // Funciona como nuestro "puntero"
};

class ListaConArreglo {
private:
    Nodo memoria[MAX_NODOS]; // El arreglo estático pre-asignado
    int head;                // Índice del primer elemento de la lista
    int libre;               // Índice del primer nodo disponible

public:
    ListaConArreglo() {
        head = NULL_INDEX;
        libre = 0;
        
        // Inicializar la lista de nodos libres
        // Cada nodo apunta al siguiente, formando una cadena de vacíos
        for (int i = 0; i < MAX_NODOS - 1; i++) {
            memoria[i].siguiente = i + 1;
        }
        memoria[MAX_NODOS - 1].siguiente = NULL_INDEX; // El último no tiene siguiente
    }

    void insertarAlInicio(int nuevoDato) {
        if (libre == NULL_INDEX) {
            std::cout << "Error: Memoria llena." << std::endl;
            return;
        }

        // 1. Tomamos el primer nodo libre
        int nuevoNodoIndex = libre;
        
        // 2. Actualizamos la lista de libres
        libre = memoria[libre].siguiente;

        // 3. Insertamos el dato
        memoria[nuevoNodoIndex].dato = nuevoDato;

        // 4. Conectamos el nuevo nodo a la lista existente
        memoria[nuevoNodoIndex].siguiente = head;
        head = nuevoNodoIndex;
    }
    
    // Aquí irían métodos para eliminar, recorrer, etc.
};