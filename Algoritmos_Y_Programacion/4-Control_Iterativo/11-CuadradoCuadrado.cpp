#include <iostream>
using namespace std;

/*
  Imprime cuadrados concéntricos en una matriz impar N x N.
  - Capas pares (0,2,4,...) contienen cuadrados.
  - Cada cuadrado dibuja su borde con 'X'.
  - Dentro de una capa par, en las posiciones espaciadas mostramos 'v'.
  - Capas impares quedan vacías para separar los cuadrados.
*/

int main() {
    int N;
    cout << "Ingrese su N impar: ";
    if (!(cin >> N)) return 0;
    if ((N & 1) == 0) {
        cout << "Su N es par, botalo" << endl;
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int layer = min(min(i, j), min(N - 1 - i, N - 1 - j));
            if (layer % 2 == 0) {
                // borde del cuadrado de esta capa
                if (i == layer || i == N - 1 - layer || j == layer || j == N - 1 - layer) {
                    cout << 'X';
                } else if (((i - layer) % 2 == 0) && ((j - layer) % 2 == 0)) {
                    // puntos interiores separados dentro de la capa
                    cout << 'v';
                } else {
                    cout << ' ';
                }
            } else {
                // capa impar: separación entre cuadrados
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}