#include <chrono> // Se incluye la cabecera para usar las funcionalidades de chrono [cite: 15]
#include<iostream>
using namespace std;
using namespace chrono; // Para no tener que escribir 'std::chrono::' todo el tiempo [cite: 16]

// ..Funciones.. //

int main() { // El punto de entrada de tu programa

    // Captura el tiempo actual con la máxima resolución disponible del sistema
    auto startTime = high_resolution_clock::now(); 
    cout<<"monda"<<endl;
    // ..codigo a medir.. // Aquí es donde colocarás el código de tu algoritmo de laberinto 
    // (una de tus versiones de backtracking) para medir su tiempo de ejecución[cite: 15].

    // Captura el tiempo actual nuevamente, al finalizar la ejecución del código a medir
    auto endTime = high_resolution_clock::now(); 

    // Calcula la duración. 'duration<float, milliseconds>' especifica que el resultado 
    // será un número flotante y las unidades serán milisegundos (ms)[cite: 15].
    duration<float, milli> duration = endTime - startTime; 

    // Obtiene el valor numérico de la duración en milisegundos.
    double finaltime = duration.count(); 
    cout<<finaltime<<endl;

    // Puedes imprimir o usar 'finaltime' para tus comparaciones
    // cout << "Tiempo de ejecución: " << finaltime << " ms" << endl;

    return 0;
}