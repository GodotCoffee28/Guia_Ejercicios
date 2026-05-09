#include <iostream>

// Variables globales según el diagrama
int a = 2, b = 4, c = 5;

// Función para imprimir valores
void print(int x, int y, int z) {
    std::cout << x << " " << y << " " << z << std::endl;
}

// Función a0 con paso de parámetros por referencia
int a0(int &a, int c) {
    print(a, b, c);
    return a + b+ c;
}

// Función a1 con paso de parámetros por referencia y valor
int a1(int &b, int c, int &a) {
    for (int i = 0; i < c; i++) {
        b += i;
    }
    {
    int a = 10;
    c = a; // c local de a1 se establece en 3
    print(b, c, a);
    }
    return a0(a, b);
}

// Función principal
int main() {
    int a = 3; // Variable local a en main
    print(a, b, c);
    a = a1(a, b, c);
    print(b, c, a);
    b = a0(c, a);
    print(a, b, c);
    return 0;
}