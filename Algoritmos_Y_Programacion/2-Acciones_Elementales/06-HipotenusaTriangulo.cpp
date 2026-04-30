/*6. Escriba un algoritmo que dadas las longitudes de los catetos de un triángulo
rectángulo calcule la longitud de su hipotenusa.*/

#include<iostream>
#include<math.h>
using namespace std;

//Pitagoras
int main(){

    int CA=0, CO=0;
    cin>> CA>>CO;

    float H = 0;

    H = sqrt(pow(CA,2) + pow(CO,2));

    cout<<H;

    return 0;
}