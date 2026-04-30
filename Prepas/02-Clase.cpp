#include<iostream>
#include<cmath>
using namespace std;
/*El IMC resulta de la división de la masa del individuo (en kilogramos)
entre el cuadrado de la estatura (en metros). El índice de masa corporal es
un indicador del peso de una persona en relación con su altura.
Clasificación del IMC de acuerdo con la OMS de la ONU:
(a) Menor a 16: Criterio de ingreso.
(b) 16 a 16.9: infrapeso.
(c) 17 a 18.4: bajo peso.
(d) 18.5 a 24.9: peso normal.
(e) 25 a 29.9: sobrepeso.
(f) 30 a 34.9: obesidad premórbida.
(g) 40 a 45: obesidad mórbida.
(h) Mayor a 45: obesidad hipermórbida.
Escriba un algoritmo que dado el peso de una persona en libras (1 libra =
0, 453592 Kg) y su estatura en centímetros, calcule su IMC e indique como
salida el peso en kilogramos, el valor de IMC de la persona y la categoría
en la cual fue clasificado.*/

int main(){
    float PesoEnLibras;
    float AlturaCentimetros;

    cout<<"Ingrese su Peso en libras y su altura en CM";
    cin>> PesoEnLibras>> AlturaCentimetros;
    //1 libra = 0,453592 Kg

    float AlturaMetros = AlturaCentimetros / 100;
    float PesoKg = PesoEnLibras * 0.453592;

    float IMC = PesoKg / (AlturaMetros * AlturaMetros); // pow(AlturaMetros, 2)

    if(IMC >= 16 &&  IMC <= 16.9){
        cout<<"Infrapeso"<<endl;

    } else if (IMC >= 17 && IMC <= 18.4){
        cout<<"Bajo peso"<<endl;

    }else if (IMC >= 18.5 && IMC <= 24.9){
        cout<<"Peso normal"<<endl;

    }else if (IMC >= 25 && IMC <= 29.9){
        cout<<"Sobre peso"<<endl;

    }else if (IMC >= 30 && IMC <= 34.9){
        cout<<"Obesidad PreMorbida"<<endl;

    }else if (IMC >= 40 && IMC <= 45){
        cout<<"Obesidad Morbidad"<<endl;

    }else if (IMC > 45){
        cout<<"Obesidad HiperMorbida"<<endl;
    }
    



    return 0;
}