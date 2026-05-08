#include<iostream>
using namespace std;

//1 Complejidad constante  - O(1)
//Ejemplo: Acceder a un elemento en un arregll

int obtenerElemento(int arr[], int indice){
    return arr[indice]; //Solo 1 operacion
}
/*Explicacion:
-No importa si el arreglo tiene 10 o 10000 elementos, siempre se hace una sola
operacion (acceso directo a memoria)
-No depende de n (tamaño del arreglo)*/

// 2 Complejidad lineal - O(n)
//Ejemplo: Sumar todos los elementos de un arreglo

int sumarArreglo(int arr[], int n){ //2 operaciones
    int suma = 0;
    for(int i=0; i<n; i++){//Acceder al arreglo
        suma+=arr[i]; //Hacer la suma
    }
    return suma;
}

/*Explicacion
- El bucle for se ejecuta n veces (una por cada elemento)
- Operaciones totales = n * 2 -> O(2n)
En realidad en el ejemplo son 4 contando la comparacion logica y el i++  i < n entonces seria O(N+2N) */

//3 Complejidad cuadratica -O(n^2)

//Ejemplo: comparar todos los pares de elementos de un arreglo

void compararPares(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i] << " vs "<<arr[j] <<endl;
        }
    }
}

/*Explicacion
-Bucle externo (i): n veces
-Bucle interno (j): n veces por cada i.
-Total de iteraciones = n * n = n^2 -> O(n^2)*/

//4 Complejidad logaritmica - O(log n)
//Ejemplo Busqueda binaria (en un arreglo ordenado)

int busquedaBinaria(int arr[], int n, int objetivo){
    int izquierda = 0, derecha = n -1;
    while(izquierda <=derecha){
        int medio = izquierda + (derecha-izquierda) / 2;
        if(arr[medio] == objetivo) return medio;
        if(arr[medio] < objetivo) izquierda = medio + 1;
        else derecha = medio - 1;
    }
    return -1;
}

/*Explicacion (¿De donde sale el logaritmo?)
Divide el problema a la mitad en cada paso:

Si n = 8 (tamaño del arreglo), en el peor caso:
Paso 1: n = 8 -> busqueda en la mitad (4 elementos restantes)
Paso 2: n = 4 -> busqueda en la mitad (2 elemento restante)
Paso 3: n = 2-> busqueda en la mitad (1 elemento restante)
Paso 4: n = 1 -> encuentra (o no ) el elemento
numero de pasos = log2(n):
Para n= 8 -> log2(8) = 3 pasos (ya que 2^3 = 8)

en general, el algoritmo descarta la mitad de los datos en cada iteracion
*/

//5 Complejidad lineal logaritmica - O(n log n)
// Ejemplo Merge sort (ordenamiento eficiente)
void merge(int arr[], int inicio, int medio, int fin);
void mergeSort(int arr[], int inicio, int fin){
    if(inicio < fin){
        int medio = inicio + (fin -inicio)/2;
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}

// 6 Complejidad cubica - O (n^3)

//Ejemplo: Tres bucles anidados( Operaciones en una matriz)

void matriz3D(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<< i <<"," << j << "," << endl;
            }
        }
    }
}

//7 Complejidad Exponencial - O(2^n)
// Ejemplo: subconjuntos de un conjunto (backtraking)

void generarSubconjuntos(int arr[], int  n, int indice, string subconjunto){
    if(indice == n){
        cout << "{" << subconjunto <<"}" <<endl;
        return;
    }

    //incluir el elemento actual
    //generarSubconjuntos( arr, n, indice + 1, subconjunto + to_string(arr[indice]))
}


//
