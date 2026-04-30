/*9. Escriba un algoritmo que tome como entrada la base y la altura de un
triángulo, el radio de un círculo y determine si el triángulo tiene un área
mayor al círculo.*/

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int altura_t = 0, base_t = 0, radio_c=0;
    cin>>altura_t>>base_t>>radio_c;

    int area_t = (base_t * altura_t)/2;

    float PI = 3.1415927;
    int area_c = PI * pow(radio_c,2);

    bool t_mayor_c = area_t > area_c;

    cout<<t_mayor_c;

    return 0;
}