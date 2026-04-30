#include <iostream>

using namespace std;

/*Problema: Dado un número N, desarrolle una función 
recursiva que calcule la secuencia de números de Fibonacci para N.*/

// Devuelve el termino n-esimo de Fibonacci.
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Muestra recursivamente los primeros n terminos de Fibonacci.
void mostrarSecuenciaFibonacci(int n, int i = 0) {
    if (i >= n) {
        return;
    }
    cout << fibonacci(i) << " ";
    mostrarSecuenciaFibonacci(n, i + 1);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de terminos N: ";
    cin >> n;

    if (n < 0) {
        cout << "N debe ser mayor o igual a 0.\n";
        return 0;
    }

    cout << "Secuencia Fibonacci (" << n << " terminos): ";
    mostrarSecuenciaFibonacci(n);
    cout << "\n";

    if (n > 0) {
        cout << "Termino N-esimo (indice " << (n - 1) << "): " << fibonacci(n - 1) << "\n";
    }

    return 0;
}