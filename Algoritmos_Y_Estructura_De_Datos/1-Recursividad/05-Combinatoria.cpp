#include<iostream>
using namespace std;

//Problema: Construya una función recursiva que calcule el valor de la combinatoria de 2 números enteros.

/*La combinatoria en terminos simples:
    Tengo N objetos y quiero saber si agarrando R de esos N objetos de cuantas formas puedo
    combinarlos sin importar el orden
    Por eso R <= N
*/
//Hay 2 Formas de resolver este problema

// Forma 1:
    // Haciendo uso de la def de combinatoria. C(n, r) = n! / (r! * (n-r)!)

    //Hacemos la función de factorial recursivo.
    unsigned long long factorialRecursivo(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorialRecursivo(n - 1);
    }

    //Y la usamos para la combinatoria
    unsigned long long combinatoriaPorFormula(int n, int r) {
        if (n < 0 || r < 0 || r > n) { // Sin números negativos
            return 0;
        }
        return factorialRecursivo(n) /
            (factorialRecursivo(r) * factorialRecursivo(n - r));
    }

// Forma 2: combinatoria recursiva (identidad de Pascal)
    /*Combinatoria de numeros enteros.
    la identidad de pascal, esta relacion nos 
    permite definir el valor de n, r. esta definida de la siguiente forma:
    C(n,r)=C(n-1,r-1)+C(n-1, r)*/
    unsigned long long combinatoriaRecursiva(int n, int r) {
        if (n < 0 || r < 0 || r > n) {
            return 0;
        }
        if (r == 0 || r == n) {
            return 1;
        }
        return combinatoriaRecursiva(n - 1, r - 1) + combinatoriaRecursiva(n - 1, r);
    }

int main() {
    int n, r;

    cout << "Ingrese n y r: ";
    cin >> n >> r;

    cout << "Combinatoria por formula: " << combinatoriaPorFormula(n, r) << '\n';
    cout << "Combinatoria recursiva: " << combinatoriaRecursiva(n, r) << '\n';

    return 0;
}