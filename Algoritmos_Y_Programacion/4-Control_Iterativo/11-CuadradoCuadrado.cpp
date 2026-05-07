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
            bool printed = false;
            int maxLayer = (N - 1) / 2;
            for (int k = 0; k <= maxLayer; ++k) {
                // sólo usamos capas pares para los cuadrados visibles
                if (k % 2 != 0) continue;

                // borde de la capa k
                if (i == k || i == N - 1 - k || j == k || j == N - 1 - k) {
                    cout << 'X';
                    printed = true;
                    break;
                }

                // puntos interiores espaciados dentro de la capa k
                if (i > k && i < N - 1 - k && j > k && j < N - 1 - k) {
                    if (((i - k) % 2 == 0) && ((j - k) % 2 == 0)) {
                        cout << 'v';
                        printed = true;
                        break;
                    }
                }
            }
            if (!printed) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}