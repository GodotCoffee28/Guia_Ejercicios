/*4. Escriba un algoritmo que reciba como entrada los coeficientes A, B y C
de una ecuación de segundo grado (Ax2 + Bx + C = 0), e imprima por
pantalla los valores de x. Asuma que la ecuación siempre tiene solución
en números reales. Recuerde que la solución de una ecuación de segundo
grado viene dada por x = −b±√b2−4ac / 2a*/

#include<iostream>
#include<math.h>
using namespace std;



int main(){
    int A=0,B,C;
    C = B = A;
    cin>>A>>B>>C;

    float x1 = 0, x2 = 0;
    // B*B

    //Agrupamos todo lo de arriba y todo lo de abajo bien
    x1 = (-B + sqrt(pow(B,2) - 4 * A * C)) / (2 * A);
    x2 = (-B - sqrt(pow(B,2) - 4 * A * C)) / (2 * A);

    cout<<x1<<endl<<x2;

    return 0;
}