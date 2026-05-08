#include <iostream>
using namespace std;

void fibonachosecuencia(int n, int a = 0, int b = 1);

int main() {
    int n;
    cout << "Elija hasta que n de la secuencia de Fibonacci: ";
    cin >> n;

    cout << "La sucesión de los números de Fibonacci hasta " << n << " o igual es: ";
    fibonachosecuencia(n);
    return 0;
}

void fibonachosecuencia(int n, int a, int b) {
    if (a > n) { // Condición de parada: cuando el número actual supera n
        return;
    }
    cout << a << " "; // Imprime el número actual
    fibonachosecuencia(n, b, a + b); // Llamada recursiva con los siguientes valores
}