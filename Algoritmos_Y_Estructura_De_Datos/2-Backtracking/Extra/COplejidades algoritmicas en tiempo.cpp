
#include <iostream>
#include <vector>
#include <algorithm> // Para max_element
#include <utility> // Para swap
#include <string>

using namespace std;
void ejemploAccesoO1(const vector<int>& arr, int indice) {
    // Operación de complejidad constante: acceder a un elemento por su índice.
    // No importa el tamaño del arreglo, esta operación siempre toma el mismo tiempo.
    if (indice >= 0 && indice < arr.size()) {
        cout << "Elemento en el indice " << indice << ": " << arr[indice] << endl;
    } else {
        cout << "Indice fuera de rango." << endl;
    }
}

// Función para encontrar el elemento máximo en un vector
int encontrarMaximo(const vector<int>& arr) {
    if (arr.empty()) {
        cerr << "El vector esta vacio." << endl;
        return -1; // O manejar error de otra manera
    }

    int maxVal = arr[0]; // Inicializamos con el primer elemento
    // Bucle for que se ejecuta n veces (una por cada elemento) [cite: 4]
    for (int i = 1; i < arr.size(); ++i) {
        // Comparación y posible asignación
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Bucle externo: recorre el arreglo n-1 veces
    // En cada pasada, el elemento más grande "burbujea" hasta su posición final.
    for (int i = 0; i < n - 1; ++i) { // n iteraciones (aproximadamente n)
        // Bucle interno: compara elementos adyacentes y los intercambia si están en el orden incorrecto
        for (int j = 0; j < n - i - 1; ++j) { // n iteraciones por cada 'i' (aproximadamente n)
            // Comparación
            if (arr[j] > arr[j + 1]) {
                // Intercambio
                swap(arr[j], arr[j + 1]); // O(1)
            }
        }
    }
}

// Función de búsqueda binaria recursiva
int busquedaBinaria(const vector<int>& arr, int inicio, int fin, int objetivo) {
    // Caso base: el rango es inválido (elemento no encontrado)
    if (inicio > fin) { // O(1)
        return -1; // O(1)
    }

    int medio = inicio + (fin - inicio) / 2; // O(1)

    // Si el elemento medio es el objetivo
    if (arr[medio] == objetivo) { // O(1)
        return medio; // O(1)
    }
    // Si el objetivo está en la mitad izquierda
    else if (arr[medio] > objetivo) { // O(1)
        return busquedaBinaria(arr, inicio, medio - 1, objetivo); // Llama recursivamente a la mitad izquierda
    }
    // Si el objetivo está en la mitad derecha
    else {
        return busquedaBinaria(arr, medio + 1, fin, objetivo); // Llama recursivamente a la mitad derecha
    }
}

void merge(vector<int>& arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Crear arreglos temporales para las dos mitades
    vector<int> izquierda(n1);
    vector<int> derecha(n2);

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; ++i)
        izquierda[i] = arr[inicio + i];
    for (int j = 0; j < n2; ++j)
        derecha[j] = arr[medio + 1 + j];

    // Combinar los arreglos temporales de nuevo en arr[inicio..fin]
    int i = 0; // Índice inicial del primer sub-arreglo
    int j = 0; // Índice inicial del segundo sub-arreglo
    int k = inicio; // Índice inicial del sub-arreglo mezclado

    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de izquierda[], si los hay
    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de derecha[], si los hay
    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) { // Condición de parada para la recursión
        // Encontrar el punto medio del arreglo
        int medio = inicio + (fin - inicio) / 2; // O(1)

        // Llamar recursivamente a mergeSort para la mitad izquierda
        mergeSort(arr, inicio, medio); // Mitad izquierda (n/2) [cite: 16]
        // Llamar recursivamente a mergeSort para la mitad derecha
        mergeSort(arr, medio + 1, fin); // Mitad derecha (n/2) [cite: 16]

        // Combinar las dos mitades ordenadas
        merge(arr, inicio, medio, fin); // Combinar (O(n)) [cite: 16]
    }
}

// Función para procesar una matriz 3D (ejemplo hipotético de operación)
void procesarMatriz3D(int dim) {
    // Si estuviéramos trabajando con una matriz 3D, los bucles accederían a sus dimensiones.
    // Aquí, para simplificar, solo mostramos el patrón de bucles anidados.
    cout << "Procesando con complejidad cubica para dimension " << dim << endl;
    for (int i = 0; i < dim; ++i) { // Bucle 1: n iteraciones
        for (int j = 0; j < dim; ++j) { // Bucle 2: n iteraciones por cada 'i'
            for (int k = 0; k < dim; ++k) { // Bucle 3: n iteraciones por cada 'j'
                // Operación constante dentro del bucle más interno
                // Por ejemplo, cout << i * j * k << " ";
            }
        }
    }
    cout << "Procesamiento cubico completado." << endl;
}

// Función recursiva para generar todos los subconjuntos
void generarSubconjuntos(const vector<int>& arr, int n, int indice, string subconjuntoActual) {
    // Caso base: hemos procesado todos los elementos
    if (indice == n) { // O(1)
        cout << "{" << subconjuntoActual << "}" << endl; // O(1)
        return;
    }

    // Opción 1: Incluir el elemento actual en el subconjunto
    // Se llama recursivamente para el siguiente elemento, incluyendo el actual.
    generarSubconjuntos(arr, n, indice + 1, subconjuntoActual + to_string(arr[indice]) + " ");

    // Opción 2: Excluir el elemento actual del subconjunto
    // Se llama recursivamente para el siguiente elemento, sin incluir el actual.
    generarSubconjuntos(arr, n, indice + 1, subconjuntoActual);
}
// Función recursiva para generar todas las permutaciones
void permutaciones(vector<int>& arr, int inicio, int n) {
    // Caso base: cuando 'inicio' llega a 'n', se ha generado una permutación completa
    if (inicio == n) { // O(1)
        for (int i = 0; i < n; ++i) { // O(n) para imprimir
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recorrer los elementos desde 'inicio' hasta 'n-1'
    for (int i = inicio; i < n; ++i) {
        // Intercambiar el elemento actual con el elemento en 'inicio'
        swap(arr[inicio], arr[i]); // O(1)

        // Llamada recursiva para generar permutaciones del sub-arreglo restante
        permutaciones(arr, inicio + 1, n); // Llamada recursiva

        // Deshacer el intercambio (backtrack) para restaurar el arreglo original
        // Esto es crucial para explorar otras permutaciones sin afectar llamadas previas.
        swap(arr[inicio], arr[i]); // O(1)
    }
}



void imprimirVector(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}



int main() {
    vector<int> miVector1 = {10, 20, 30, 40, 50};
    ejemploAccesoO1(miVector1, 2); // Acceder al elemento en el índice 2 (valor 30)

    vector<int> miVector2 = {5, 2, 8, 1, 9, 4};
    cout << "El elemento maximo es: " << encontrarMaximo(miVector2) << endl;

    vector<int> miVector3 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Vector original: ";
    imprimirVector(miVector3);

    bubbleSort(miVector3);

    cout << "Vector ordenado: ";
    imprimirVector(miVector3);


    vector<int> miVector4 = {10, 20, 30, 40, 50, 60, 70, 80};
    // Asegurarse de que el vector esté ordenado para la búsqueda binaria
    // sort(miVector4.begin(), miVector4.end()); // Si no estuviera ya ordenado

    int objetivo1 = 30;
    int resultado1 = busquedaBinaria(miVector4, 0, miVector4.size() - 1, objetivo1);
    if (resultado1 != -1) {
        cout << "El elemento " << objetivo1 << " se encuentra en el indice: " << resultado1 << endl;
    } else {
        cout << "El elemento " << objetivo1 << " no se encuentra en el vector." << endl;
    }

    int objetivo2 = 90;
    int resultado2 = busquedaBinaria(miVector4, 0, miVector4.size() - 1, objetivo2);
    if (resultado2 != -1) {
        cout << "El elemento " << objetivo2 << " se encuentra en el indice: " << resultado2 << endl;
    } else {
        cout << "El elemento " << objetivo2 << " no se encuentra en el vector." << endl;
    }

        vector<int> miVector5 = {38, 27, 43, 3, 9, 82, 10};
    cout << "Vector original: ";
    imprimirVector(miVector5);

    mergeSort(miVector5, 0, miVector5.size() - 1);

    cout << "Vector ordenado: ";
    imprimirVector(miVector5);

        procesarMatriz3D(5); // Prueba con una dimensión pequeña

            vector<int> miConjunto = {1, 2, 3};
    cout << "Subconjuntos del conjunto: { ";
    for (int x : miConjunto) {
        cout << x << " ";
    }
    cout << "}" << endl;
    generarSubconjuntos(miConjunto, miConjunto.size(), 0, "");
        vector<int> miArreglo = {1, 2, 3};
    cout << "Permutaciones del arreglo: ";
    permutaciones(miArreglo, 0, miArreglo.size());
    return 0;
}



