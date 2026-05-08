#include<iostream>
using namespace std;
/*Haga un algoritmo que reciba como entrada un número entre 1 y 12 e
imprima el nombre del mes correspondiente. Tome en cuenta posibles
valores erróneos en la entrada.*/

int main(){
    
    int Numero;
    cout<<"Introduzca un numero entre 1 y 12"<<endl;
    cin>> Numero;
    if(true){ 

    }

    switch(Numero){

        case 1:cout<<"Enero"<<endl;break;
        case 2:cout<<"Febrero"<<endl;
        case 3:cout<<"Marzo"<<endl;
        case 4:cout<<"Abril"<<endl;
        case 5:cout<<"Mayo"<<endl;
        case 6:cout<<"Junio"<<endl;
        case 7:cout<<"Julio"<<endl;
        case 8:cout<<"Agosto"<<endl;
        case 9:cout<<"Septiembre"<<endl;
        case 10:cout<<"Octubre"<<endl;
        case 11:cout<<"Noviembre"<<endl;
        case 12:cout<<"Diciembre"<<endl;

        default: cout<<"Ese no es un mes del anio";
    }


    return 0;
}